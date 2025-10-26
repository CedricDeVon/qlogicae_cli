#include "pch.hpp"

#include "cli_file_system.hpp"

namespace QLogicaeCLI
{
	CLIFileSystem::CLIFileSystem()
	{

	}

	CLIFileSystem::~CLIFileSystem()
	{

	}

	bool CLIFileSystem::replace_file_if_found(
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

	bool CLIFileSystem::remove_file_or_folder_if_found(
		const std::string& path
	)
	{
		if (std::filesystem::exists(path))
		{
			std::filesystem::remove(path);
		}

		return true;
	}

	bool CLIFileSystem::copy_file_or_folder(
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

	bool CLIFileSystem::is_file_or_folder_path_found(
		const std::string& path
	)
	{
		if (!std::filesystem::exists(path))
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::setup()",
				"File or folder path '" + path + "' does not exist"
			);

			return false;
		}

		return true;
	}

	bool CLIFileSystem::create_folder_path(
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

	std::string CLIFileSystem::setup_result_output_file(
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

	CLIFileSystem& CLIFileSystem::get_instance()
	{
		static CLIFileSystem instance;

		return instance;
	}

	void CLIFileSystem::get_instance(
		QLogicaeCore::Result<CLIFileSystem*>& result
	)
	{
		static CLIFileSystem instance;

		result.set_to_good_status_with_value(&instance);
	}
}
