#include "windows-path.hh"

WindowsPath::WindowsPath(char drive)
    : drive_letter_(drive)
{}

std::string WindowsPath::to_string() const
{
    std::string res;
    res += drive_letter_;
    res += ":\\";
    for (auto it = path_.begin(); it != path_.end(); ++it)
    {
        res += *it;
    }
    return res;
}

bool WindowsPath::check_name(const std::string& name)
{
    int c = 0;
    while (name[c] != '\0')
    {
        if (name[c] == ':' || name[c] == '\"' || name[c] == '|'
            || name[c] == '?' || name[c] == '*')
        {
            return false;
        }
        c += 1;
    }
    return true;
}

Path& WindowsPath::join(const std::string& tail, bool is_file)
{
    if (check_name(tail) && !final_ && tail != "nope")
    {
        path_.push_back(tail);
        final_ = is_file;
        if (!is_file)
        {
            path_.push_back("\\");
        }
    }
    return *this;
}