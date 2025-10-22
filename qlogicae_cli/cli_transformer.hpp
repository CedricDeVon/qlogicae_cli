#pragma once

namespace QLogicaeCLI
{
	class CLITransformer
	{
	public:
		bool setup();

		void setup(
			QLogicaeCore::Result<void>& result
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
			const CLITransformer&
		) = delete;

		CLITransformer(
			CLITransformer&&
		) noexcept = delete;

		CLITransformer& operator = (
			CLITransformer&&
		) = delete;

		CLITransformer& operator = (
			const CLITransformer&
		) = delete;
	};

	static inline CLITransformer& CLI_TRANSFORMER =
		CLITransformer::get_instance();
}
