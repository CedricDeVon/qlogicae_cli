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
