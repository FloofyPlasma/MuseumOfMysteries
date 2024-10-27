#include "IO/File.h"

File::File() { this->fileName = ""; }

File::~File() { File::Close(); }

File::File(const std::string& fileName, bool truncate) { File::Open(fileName, truncate); }

auto File::Open(const std::string& fileName, bool truncate) -> bool
{
	this->fileName = fileName;

	// If we have a file open already, close it
	File::Close();

	if (truncate)
	{
		this->file.open(this->fileName,
				std::fstream::in | std::fstream::out | std::fstream::binary | std::fstream::trunc);
	}
	else
	{
		this->file.open(this->fileName, std::fstream::in | std::fstream::out | std::fstream::binary);
	}

	return File::IsOpen();
}

void File::Close()
{
	if (this->file.is_open())
	{
		this->file.close();
	}
}

auto File::Read(std::vector<char>& data) const -> bool
{
    size_t fileLength = File::GetLength();

    data.reserve(fileLength);
    data.resize(fileLength);

    return File::Read(data.data(), fileLength);
}

auto File::Read(char* data, size_t length) const -> bool
{
	if (File::IsOpen() && this->file.good())
	{
		this->file.read(data, length); // Read length bytes from the file.
		this->file.seekg(0, std::ios::beg); // Read from begining of file.

        // Check if we failed to read.
		return !this->file.fail();
	}
    // Something went wrong here, and the file wasn't open or good.
    // Return false.
    // TODO: Print an error message?
	return false;
}

auto File::Write(const char* data, size_t length, bool append, bool createFileIfNotExist) -> bool
{
    // Try to create the file
    if ((!File::IsOpen() || !this->file.good()) && createFileIfNotExist)
    {
        File::Open(this->fileName, true);
    }

    if (File::IsOpen() && this->file.good())
    {
        if (append)
        {
            // Seek end of file
            this->file.seekp(0, std::ios::end);
        }

        // Write to the file stream
        this->file.write(data, length);

        // Flush the file stream
        this->file.flush();

        // Move to start of file
        this->file.seekp(0, std::ios::beg);

        // Check if we failed to write.
        return !this->file.fail();
    }

    // Something went wrong here, and the file wasn't open or good.
    // Return false.
    // TODO: Print an error message?
	return false;
}

auto File::IsOpen() const -> bool
{
    return this->file.is_open();
}

auto File::GetLength() const -> size_t
{
    // Open the file, and immediately seek to end
    std::ifstream input(this->fileName, std::ios::binary | std::ios::ate);
    // Get current position in file stream, cast it to a size_t and return.
    return (input.good() ? static_cast<size_t>(input.tellg()) : 0);
}