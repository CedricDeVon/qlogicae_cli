#pragma once



namespace QLogicaeCLI
{
	class CLILogger
	{
	public:
		bool setup();

		void setup(
			QLogicaeCore::Result<void>& result
		);

		std::future<bool> setup_async();

		void setup_async(
			QLogicaeCore::Result<std::future<void>>& result
		);

        void log_running(
            const bool& is_enabled = true
        );

        void log_complete(
            const bool& is_enabled = true
        );

        void log_running_async(
            const bool& is_enabled = true
        );

        void log_complete_async(
            const bool& is_enabled = true
        );

		static CLILogger& get_instance();

		static void get_instance(
			QLogicaeCore::Result<CLILogger*>& result
		);

	protected:
		CLILogger();

		~CLILogger();

		CLILogger(
			const CLILogger&
		) = delete;

		CLILogger(
			CLILogger&&
		) noexcept = delete;

		CLILogger& operator = (
			CLILogger&&
			) = delete;

		CLILogger& operator = (
			const CLILogger&
			) = delete;
	};

	static inline CLILogger& CLI_LOGGER =
		CLILogger::get_instance();
}
