#include "ciutils/ciutils.hh"

#include <fstream>
#include <yaml-cpp/yaml.h>

#include "ciutils/ciutils.hh"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <yaml-cpp/yaml.h>

namespace CIUtils
{

    CIData parse_ci_file(const std::string& filename)
    {
        CIData data;

        YAML::Node config = YAML::LoadFile(filename);
        data.stages = config["stages"].as<std::vector<std::string>>();

        for (const auto& node : config)
        {
            // For each node in config, parse the stage and scripts using the
            // job name as first key.
            auto job = node.first.as<std::string>();

            // Skip the "stages" job as it is a special gitlab yaml node that we
            // have previously parsed.
            if (job == "stages")
                continue;

            // Retrieves the stage field of the job key.
            auto stage = config[job]["stage"].as<std::string>();
            auto scripts = config[job]["script"].as<std::vector<std::string>>();

            Job job_obj;
            job_obj.name = job;
            job_obj.stage = stage;
            data.jobs.push_back(job_obj);

            for (const auto& script : scripts) {
                // Extract the first word of each script line and add it to the set
                size_t pos = script.find_first_of(" \t");
                if (pos != std::string::npos) {
                    std::string command = script.substr(0, pos);
                    data.commands.insert(command);
                } else {
                    data.commands.insert(script);
                }
            }
        }

        return data;
    }
} // namespace CIUtils