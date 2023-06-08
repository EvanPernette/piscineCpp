#include "ciutils/ciutils.hh"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    CIUtils::CIData data = CIUtils::parse_ci_file(argv[1]);

    std::cout << "stages(" << data.stages.size() << "):\n";
    for (const auto& stage : data.stages)
    {
        std::cout << "  " << stage << "\n";
    }

    std::cout << "\njobs(" << data.jobs.size() << "):\n";
    for (const auto& job : data.jobs)
    {
        std::cout << "  " << job.name << " (" << job.stage << ")\n";
    }

    std::cout << "\ncommands(" << data.commands.size() << "):\n";
    for (const auto& cmd : data.commands)
    {
        std::cout << "  " << cmd << "\n";
    }

    return 0;
}