#pragma once

#include "utilities.hpp"

#include "qlogicae_core/includes/result.hpp"

namespace QLogicaeCLI
{
	class FileSystem
	{
	public:
		bool setup();

		std::future<bool> setup_async();

		void setup_async(
			QLogicaeCore::Result<std::future<void>>& result
		);

		void setup(
			QLogicaeCore::Result<void>& result
		);

		std::future<bool> setup_async(
			const std::function<void(const bool& result)>& callback
		);

		void setup_async(			
			const std::function<void(QLogicaeCore::Result<void>& result)>& callback
		);

		bool terminate();

		std::future<bool> terminate_async();

		void terminate_async(
			QLogicaeCore::Result<std::future<void>>& result
		);

		void terminate(
			QLogicaeCore::Result<void>& result
		);

		std::future<bool> terminate_async(
			const std::function<void(const bool& result)>& callback
		);

		void terminate_async(
			const std::function<void(QLogicaeCore::Result<void>& result)>& callback
		);

		bool is_file_or_folder_path_found(
			const std::string& path
		);

		bool replace_file_if_found(
			const std::string& folder_path,
			const std::string& file_path
		);

		bool copy_file_or_folder(
			const std::string& from_path,
			const std::string& to_path
		);

		bool remove_file_or_folder_if_found(
			const std::string& path
		);

		bool create_folder_path(
			const std::string& path,
			const bool& is_enabled = true
		);

		std::string setup_result_output_file(
			const std::string& path,
			const std::string& extended_folder_path,
			const std::string& default_file_name,
			const bool& is_enabled = true
		);

		static FileSystem& get_instance();

		static void get_instance(
			QLogicaeCore::Result<FileSystem*>& result
		);

	protected:
		FileSystem();

		~FileSystem();

		FileSystem(
			const FileSystem& instance
		) = delete;

		FileSystem(
			FileSystem&& instance
		) noexcept = delete;

		FileSystem& operator = (
			FileSystem&& instance
		) = delete;

		FileSystem& operator = (
			const FileSystem& instance
		) = delete;
	};

	static inline FileSystem& FILE_SYSTEM =
		FileSystem::get_instance();
}
