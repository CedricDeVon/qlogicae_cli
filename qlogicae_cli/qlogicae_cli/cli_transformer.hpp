#pragma once

#include "qlogicae_core/result.hpp"
#include "qlogicae_core/logger.hpp"
#include "qlogicae_core/transformer.hpp"

namespace QLogicaeCLI
{
	class CLITransformer
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

		std::string to_input_command_path(
			const std::string command_path,
			const std::string command_key
		);

		void to_input_command_path(
			QLogicaeCore::Result<std::string>& result,
			const std::string command_path,
			const std::string command_key
		);

		std::string to_log_running_timestamp(
			const bool& is_enabled = true
		);

		std::string to_log_complete_timestamp(
			const bool& is_enabled = true
		);

		std::string to_log_info_timestamp(
			const std::string& text = "",
			const bool& is_enabled = true
		);

		std::string to_log_success_timestamp(
			const std::string& text = "",
			const bool& is_enabled = true
		);

		std::string to_log_warning_timestamp(
			const std::string& text = "",
			const bool& is_enabled = true
		);

		std::string to_log_exception_timestamp(
			const std::string& text = "",
			const bool& is_enabled = true
		);

		static CLITransformer& get_instance();

		static void get_instance(
			QLogicaeCore::Result<CLITransformer*>& result
		);

	protected:
		CLITransformer();

		~CLITransformer();

		CLITransformer(
			const CLITransformer& instance
		) = delete;

		CLITransformer(
			CLITransformer&& instance
		) noexcept = delete;

		CLITransformer& operator = (
			CLITransformer&& instance
		) = delete;

		CLITransformer& operator = (
			const CLITransformer& instance
		) = delete;
	};

	static inline CLITransformer& CLI_TRANSFORMER =
		CLITransformer::get_instance();
}
