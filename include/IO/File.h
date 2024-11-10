#ifndef FILE_H
#define FILE_H

#include <cstddef>
#include <fstream>
#include <string>
#include <vector>

// TODO: This class needs some major refactoring, perhaps use a virtual filesytem instead so assets
//		 can be zipped for better data effeciency?

class File
{
	public:
	/**
	 * @brief Construct a new File object
	 *
	 */
	File();

	/**
	 * @brief Construct a new File object
	 *s
	 * @param fileName
	 * @param truncate
	 */
	File(const std::string& fileName, bool truncate = false);

	/**
	 * @brief Destroy the File object
	 *
	 */
	~File();

	/**
	 * @brief Open a file
	 *
	 * @param fileName
	 * @param truncate
	 * @return true
	 * @return false
	 */
	auto Open(const std::string& fileName, bool truncate = false) -> bool;

	/**
	 * @brief Close a file
	 *
	 */
	void Close();

	/**
	 * @brief Read data from the file
	 *
	 * @param data
	 * @return true
	 * @return false
	 */
	auto Read(std::vector<char>& data) const -> bool;

	/**
	 * @brief Read data from the file
	 *
	 * @param data
	 * @param length
	 * @return true
	 * @return false
	 */
	auto Read(char* data, size_t length) const -> bool;

	/**
	 * @brief Write to the file
	 *
	 * @param data
	 * @param length
	 * @param append
	 * @param createFileIfNotExist
	 * @return true
	 * @return false
	 */
	auto Write(const char* data, size_t length, bool append = false,
			bool createFileIfNotExist = false) -> bool;

	/**
	 * @brief Checks if a file is currently open
	 *
	 * @return true
	 * @return false
	 */
	auto IsOpen() const -> bool;

	/**
	 * @brief Checks if a file is ready for usage
	 *
	 * @return true
	 * @return false
	 */
	auto IsReady() const -> bool;

	/**
	 * @brief Get the Length of the file
	 *
	 * @return size_t
	 */
	auto GetLength() const -> size_t;

	private:
	std::string fileName;
	mutable std::fstream file;
};

#endif // FILE_H