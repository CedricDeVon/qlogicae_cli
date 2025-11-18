#include "pch.hpp"

#include "../includes/file_system.hpp"

namespace QLogicaeCLI
{
	FileSystem::FileSystem()
	{

	}

	FileSystem::~FileSystem()
	{

	}

	bool FileSystem::setup()
	{
		try
		{
			QLogicaeCore::Result<void> result;

			setup(result);

			return result.is_status_safe();
		}
		catch (const std::exception& exception)
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::FileSystem::setup()",
				exception.what()
			);

			return false;
		}
	}

	std::future<bool> FileSystem::setup_async()
	{
		std::promise<bool> promise;
		auto future = promise.get_future();

		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this,
			promise = std::move(promise)]() mutable
			{
				promise.set_value(
					setup()
				);
			}
		);

		return future;
	}

	void FileSystem::setup_async(
		QLogicaeCore::Result<std::future<void>>& result
	)
	{
		std::promise<void> promise;
		auto future = promise.get_future();

		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this,
			promise = std::move(promise)]() mutable
			{
				QLogicaeCore::Result<void> result;

				setup(
					result
				);

				promise.set_value();
			}
		);

		result.set_to_good_status_with_value(
			std::move(future)
		);
	}

	void FileSystem::setup(
		QLogicaeCore::Result<void>& result
	)
	{
		result.set_to_good_status_without_value();
	}

	std::future<bool> FileSystem::setup_async(
		const std::function<void(const bool& result)>& callback
	)
	{
		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, callback]() mutable
			{
				callback(
					setup()
				);
			}
		);
	}

	void FileSystem::setup_async(
		const std::function<void(QLogicaeCore::Result<void>& result)>& callback
	)
	{
		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, callback]() mutable
			{
				QLogicaeCore::Result<void> result;

				setup(result);

				callback(
					result
				);
			}
		);
	}

	bool FileSystem::terminate()
	{
		try
		{
			QLogicaeCore::Result<void> result;

			terminate(result);

			return result.is_status_safe();
		}
		catch (const std::exception& exception)
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::FileSystem::terminate()",
				exception.what()
			);

			return false;
		}
	}

	std::future<bool> FileSystem::terminate_async()
	{
		std::promise<bool> promise;
		auto future = promise.get_future();

		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this,
			promise = std::move(promise)]() mutable
			{
				promise.set_value(
					terminate()
				);
			}
		);

		return future;
	}

	void FileSystem::terminate_async(
		QLogicaeCore::Result<std::future<void>>& result
	)
	{
		std::promise<void> promise;
		auto future = promise.get_future();

		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this,
			promise = std::move(promise)]() mutable
			{
				QLogicaeCore::Result<void> result;

				terminate(
					result
				);

				promise.set_value();
			}
		);

		result.set_to_good_status_with_value(
			std::move(future)
		);
	}

	void FileSystem::terminate(
		QLogicaeCore::Result<void>& result
	)
	{
		result.set_to_good_status_without_value();
	}

	std::future<bool> FileSystem::terminate_async(
		const std::function<void(const bool& result)>& callback
	)
	{
		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, callback]() mutable
			{
				callback(
					terminate()
				);
			}
		);
	}

	void FileSystem::terminate_async(
		const std::function<void(QLogicaeCore::Result<void>& result)>& callback
	)
	{
		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, callback]() mutable
			{
				QLogicaeCore::Result<void> result;

				terminate(result);

				callback(
					result
				);
			}
		);
	}

	bool FileSystem::replace_file_if_found(
		const std::string& folder_path,
		const std::string& file_path
	)
	{
		if (!std::filesystem::exists(folder_path))
		{
			create_folder_path(folder_path);
		}

		if (std::filesystem::exists(file_path))
		{
			std::filesystem::remove(file_path);
		}

		return true;
	}

	bool FileSystem::remove_file_or_folder_if_found(
		const std::string& path
	)
	{
		if (std::filesystem::exists(path))
		{
			std::filesystem::remove(path);
		}

		return true;
	}

	bool FileSystem::copy_file_or_folder(
		const std::string& from_path,
		const std::string& to_path
	)
	{
		std::filesystem::copy_file(
			from_path,
			to_path,
			std::filesystem::copy_options::overwrite_existing
		);

		return true;
	}

	bool FileSystem::is_file_or_folder_path_found(
		const std::string& path
	)
	{
		if (!std::filesystem::exists(path))
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::FileSystem::is_file_or_folder_path_found()",
				"File or folder path '" + path + "' does not exist"
			);

			return false;
		}

		return true;
	}

	bool FileSystem::create_folder_path(
		const std::string& path,
		const bool& is_enabled
	)
	{
		if (!is_enabled)
		{
			return false;
		}

		if (!std::filesystem::exists(path))
		{
			std::filesystem::create_directories(path);

			return true;
		}

		return false;
	}

	std::string FileSystem::setup_result_output_file(
		const std::string& path,
		const std::string& extended_folder_path,
		const std::string& default_file_name,
		const bool& is_enabled
	)
	{
		if (!is_enabled)
		{
			return path;
		}

		if (path.empty())
		{
			create_folder_path(
				UTILITIES.RELATIVE_QLOGICAE_DOT_QLOGICAE_CLI_FOLDER_PATH +
				"\\" + extended_folder_path
			);

			return UTILITIES.RELATIVE_QLOGICAE_DOT_QLOGICAE_CLI_FOLDER_PATH +
				"\\" + extended_folder_path + "\\" + default_file_name;
		}

		return path;
	}

	FileSystem& FileSystem::get_instance()
	{
		static FileSystem instance;

		return instance;
	}

	void FileSystem::get_instance(
		QLogicaeCore::Result<FileSystem*>& result
	)
	{
		static FileSystem instance;

		result.set_to_good_status_with_value(&instance);
	}
}
