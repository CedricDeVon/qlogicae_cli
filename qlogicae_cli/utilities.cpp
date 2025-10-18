#include "pch.hpp"

#include "utilities.hpp"

namespace QLogicaeCLI
{
	Utilities::Utilities()
	{
		
	}

	std::string Utilities::get_application_full_name()
	{
		try
		{
			return APPLICATION_QLOGICAE_FILE.get_string({ "name" }) + " " +
				"(" + APPLICATION_QLOGICAE_FILE.get_string({ "version" }) + ")";
		}
		catch (const std::exception& exception)
		{
			log_exception_timestamp_async(std::string("Exception at Utilities::get_application_full_name(): ") + exception.what());

			return QLogicaeCore::UTILITIES.STRING_NONE_1;
		}
	}

	std::string Utilities::get_application_about_details()
	{
		try
		{
			return get_application_full_name() + "\n\n" +
				"ID:\n" + APPLICATION_QLOGICAE_FILE.get_string({ "id" }) + "\n\n" +
				"Description:\n" + APPLICATION_QLOGICAE_FILE.get_string({ "description" }) + "\n\n" +
				"Architecture:\n" + APPLICATION_QLOGICAE_FILE.get_string({ "architecture" }) + "\n\n" +
				"Authors:\n" + APPLICATION_QLOGICAE_FILE.get_string({ "authors" }) + "\n\n" +
				"Repository:\n" + APPLICATION_QLOGICAE_FILE.get_string({ "url" }) + "\n";
		}
		catch (const std::exception& exception)
		{
			log_exception_timestamp_async(std::string("Exception at Utilities::get_application_about_details(): ") + exception.what());

			return QLogicaeCore::UTILITIES.STRING_NONE_1;
		}
	}

	bool Utilities::replace_file_if_found(
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

	bool Utilities::remove_file_or_folder_if_found(
		const std::string& path
	)
	{
		if (std::filesystem::exists(path))
		{
			std::filesystem::remove(path);
		}

		return true;
	}

	bool Utilities::copy_file_or_folder(
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

	bool Utilities::is_file_or_folder_path_found(
		const std::string& path
	)
	{
		if (!std::filesystem::exists(path))
		{
			log_exception_timestamp_async(
				"File or folder path '" + path + "' does not exist"
			);

			return false;
		}

		return true;
	}

	bool Utilities::create_folder_path(
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

	std::string Utilities::setup_result_output_file(
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
				RELATIVE_QLOGICAE_DOT_QLOGICAE_CLI_FOLDER_PATH +
				"\\" + extended_folder_path
			);

			return RELATIVE_QLOGICAE_DOT_QLOGICAE_CLI_FOLDER_PATH +
				"\\" + extended_folder_path + "\\" + default_file_name;
		}

		return path;
	}

	void Utilities::log_running_timestamp(const bool& is_enabled)
	{
		if (is_enabled)
		{
			TIMESTAMP_LOGGER.log(
				"Running...", QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
			);
		}
	}

	void Utilities::log_complete_timestamp(const bool& is_enabled)
	{
		if (is_enabled)
		{
			TIMESTAMP_LOGGER.log(
				"Complete!", QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
			);
		}
	}

	void Utilities::log_info_timestamp(
		const std::string& text,
		const bool& is_enabled)
	{
		if (is_enabled)
		{
			TIMESTAMP_LOGGER.log(
				text, QLogicaeCore::LogLevel::INFO
			);
		}
	}

	void Utilities::log_success_timestamp(
		const std::string& text,
		const bool& is_enabled)
	{
		if (is_enabled)
		{
			TIMESTAMP_LOGGER.log(
				text, QLogicaeCore::LogLevel::SUCCESS
			);
		}
	}

	void Utilities::log_warning_timestamp(
		const std::string& text,
		const bool& is_enabled)
	{
		if (is_enabled)
		{
			TIMESTAMP_LOGGER.log(
				text, QLogicaeCore::LogLevel::WARNING
			);
		}
	}

	void Utilities::log_exception_timestamp(
		const std::string& text, const bool& is_enabled
	)
	{
		if (is_enabled)
		{
			TIMESTAMP_LOGGER.log(
				text, QLogicaeCore::LogLevel::EXCEPTION
			);
		}
	}

	void Utilities::log_running_timestamp_async(
		const bool& is_enabled)
	{
		if (is_enabled)
		{
			TIMESTAMP_LOGGER.log_async(
				"Running...", QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
			);
		}
	}

	void Utilities::log_complete_timestamp_async(
		const bool& is_enabled)
	{
		if (is_enabled)
		{
			TIMESTAMP_LOGGER.log_async(
				"Complete!", QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
			);
		}
	}

	void Utilities::log_info_timestamp_async(
		const std::string& text,
		const bool& is_enabled)
	{
		if (is_enabled)
		{
			TIMESTAMP_LOGGER.log_async(
				text, QLogicaeCore::LogLevel::INFO
			);
		}
	}

	void Utilities::log_success_timestamp_async(
		const std::string& text,
		const bool& is_enabled)
	{
		if (is_enabled)
		{
			TIMESTAMP_LOGGER.log_async(
				text, QLogicaeCore::LogLevel::SUCCESS
			);
		}
	}

	void Utilities::log_warning_timestamp_async(
		const std::string& text,
		const bool& is_enabled)
	{
		if (is_enabled)
		{
			TIMESTAMP_LOGGER.log_async(
				text, QLogicaeCore::LogLevel::WARNING
			);
		}
	}

	void Utilities::log_exception_timestamp_async(
		const std::string& text, const bool& is_enabled
	)
	{
		if (is_enabled)
		{
			TIMESTAMP_LOGGER.log_async(
				text, QLogicaeCore::LogLevel::EXCEPTION
			);
		}
	}

	std::string Utilities::transform_log_running_timestamp(
		const bool& is_enabled)
	{
		if (is_enabled)
		{
			return QLogicaeCore::TRANSFORMER.to_log_format(
				"Running...",
				QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
			);
		}

		return "";
	}

	std::string Utilities::transform_log_complete_timestamp(
		const bool& is_enabled)
	{
		if (is_enabled)
		{
			return QLogicaeCore::TRANSFORMER.to_log_format(
				"Complete!",
				QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
			);
		}

		return "";
	}

	std::string Utilities::transform_log_info_timestamp(
		const std::string& text,
		const bool& is_enabled)
	{
		if (is_enabled)
		{
			return QLogicaeCore::TRANSFORMER.to_log_format(
				text,
				QLogicaeCore::LogLevel::INFO
			);
		}

		return "";
	}

	std::string Utilities::transform_log_success_timestamp(
		const std::string& text,
		const bool& is_enabled)
	{
		if (is_enabled)
		{
			return QLogicaeCore::TRANSFORMER.to_log_format(
				text,
				QLogicaeCore::LogLevel::SUCCESS
			);
		}

		return "";
	}

	std::string Utilities::transform_log_warning_timestamp(
		const std::string& text,
		const bool& is_enabled)
	{
		if (is_enabled)
		{
			return QLogicaeCore::TRANSFORMER.to_log_format(
				text,
				QLogicaeCore::LogLevel::WARNING
			);
		}

		return "";
	}

	std::string Utilities::transform_log_exception_timestamp(
		const std::string& text, const bool& is_enabled
	)
	{
		if (is_enabled)
		{
			return QLogicaeCore::TRANSFORMER.to_log_format(
				text,
				QLogicaeCore::LogLevel::EXCEPTION
			);
		}

		return "";
	}

	bool Utilities::is_qlogicae_project_found()
	{
		if (!std::filesystem::exists("qlogicae"))
		{
			UTILITIES.log_exception_timestamp_async(std::string("qlogicae_cli must be run ajacent to a 'qlogicae' project folder"));

			return false;
		}

		return true;
	}

	Utilities& Utilities::get_instance()
	{
		static Utilities instance;

		return instance;
	}
}
