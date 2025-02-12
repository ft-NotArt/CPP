#include <iostream>
#include <fstream>

int	get_stream_len(std::ifstream &file) {
	std::streampos pos = file.tellg() ; // Get current pos
	file.seekg(0, file.end) ; // Set pos to end of stream
	int len = file.tellg() ; // Get total len of stream
	file.seekg(pos) ; // Set back stream pos to where it was
	return len ;
}

/* Copies src into out_stream, replacing every occurence of to_replace by replace_for */
void replace_each(std::ofstream &out_stream, std::string src, std::string to_replace, std::string replace_for) {
	int last_pos = 0 ;
	int found_at = -1 ;
	while ((size_t) (found_at = src.find(to_replace, found_at + 1)) != std::string::npos)
	{
		out_stream << src.substr(last_pos, found_at - last_pos) << replace_for ;
		last_pos = found_at + to_replace.size() ;
	}
	out_stream << src.substr(last_pos, found_at - last_pos) ;
}

int main(int argc, char *argv[])
{
	/* Checks number of arguments */
	if (argc != 4)
	{
		std::cerr << "Usage : ./Replace <file> <to_replace> <replace_for>" << std::endl ;
		return 1 ;
	}

	/* Open files (create a newfile if it doesn't exist) */
	std::ifstream file(argv[1]) ;
	if (!file.is_open()) { // is_open is used for clarity but simply using bool evaluation of file would work too
		std::cerr << "Error trying to open " << argv[1] << std::endl ;
		return 1 ;
	}
	std::ofstream new_file((std::string(argv[1]) + ".replace").c_str(), std::ofstream::out | std::ofstream::trunc) ;
	if (!new_file.is_open()) { // is_open is used for clarity but simply using bool evaluation of new_file would work too
		std::cerr << "Error when trying to open/create " << std::string(argv[1]) + ".replace" << std::endl ;
		return 1 ;
	}

	int len = get_stream_len(file) ;

	char *buffer = new char[len + 1] ;
	file.read(buffer, len + 1) ;
	buffer[len] = '\0' ;

	if (!file.eof()) {
		std::cerr << "Error when reading from " << argv[1] << std::endl ;
		delete[] buffer ;
		return 1 ;
	}

	replace_each(new_file, buffer, argv[2], argv[3]) ;

	delete[] buffer ;
}