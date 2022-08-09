#include <iostream>
#include <fstream>

std::string	ft_replace(std::string line, std::string s1, std::string s2)
{
	std::string	newline;
	size_t			pos;
	int				start =0;
	while ((pos = line.find(s1, start)) != std::string::npos)
	{
		newline += line.substr(start, pos - start);
		newline += s2;
		start += pos - start + s1.length();
	}
	newline += line.substr(start);
	return newline;
}
int main(int argc, char **argv)
{
	std::ifstream	file_in;
	std::ofstream	file_out;
	std::string		name;
	std::string		line;

	if (argc != 4)
		return (1);
	if (std::string(argv[1]).empty() ||std::string(argv[2]).empty() ||std::string(argv[3]).empty() )
		return (1);
	name = std::string(argv[1]);
	name += ".replace";
	file_in.open(argv[1]);
    if (!file_in.is_open())
        return (1);
    file_out.open(name.c_str());
    if (!file_out.is_open())
        return (1);
	while (std::getline(file_in, line).good())
	{
		std::string newline = ft_replace(line, argv[2], argv[3]);
		file_out << newline << std::endl;
	}
	file_in.close();
	file_out.close();
}
