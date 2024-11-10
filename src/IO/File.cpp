#include "IO/File.h"

#include <filesystem>

File::File() { this->fileName = ""; }

File::~File() { File::Close(); }

File::File(const std::string& fileName, bool truncate) { File::Open(fileName, truncate); }

auto File::Open(const std::string& fileName, bool truncate) -> bool
{
	this->fileName = fileName;

	// If we have a file open already, close it
	File::Close();

	std::ios_base::openmode mode = std::fstream::in | std::fstream::out | std::fstream::binary;

	if (truncate)
	{
		mode |= std::fstream::trunc;
	}

	this->file.open(this->fileName, mode);
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
	if (fileLength == 0)
	{
		return false;
	}

	data.resize(fileLength);

	return File::Read(data.data(), fileLength);
}

auto File::Read(char* data, size_t length) const -> bool
{
	if (!File::IsReady())
	{
		// Something went wrong here, and the file wasn't open or good.
		// Return false.
		// TODO: Print an error message?
		return false;
	}

	this->file.read(data, length); // Read length bytes from the file.
	this->file.seekg(0, std::ios::beg); // Read from begining of file.

	// Check if we failed to read.
	return !this->file.fail();
}

auto File::Write(const char* data, size_t length, bool append, bool createFileIfNotExist) -> bool
{
	// Try to create the file
	if ((!File::IsOpen() || !this->file.good()) && createFileIfNotExist)
	{
		File::Open(this->fileName, true);
	}

	if (!File::IsReady())
	{
		// Something went wrong here, and the file wasn't open or good.
		// Return false.
		// TODO: Print an error message?
		return false;
	}

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

auto File::IsOpen() const -> bool { return this->file.is_open(); }

auto File::IsReady() const -> bool { return File::IsOpen() && this->file.good(); }

auto File::GetLength() const -> size_t
{
	return static_cast<size_t>(std::filesystem::file_size(this->fileName));
}