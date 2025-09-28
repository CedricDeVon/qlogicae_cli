#pragma once

#include "utilities.hpp"

#include "qlogicae_core.hpp"

namespace QLogicaeCLI
{
	class Application
	{
	public:
		bool parse();
		bool setup(int, char**);
	
		static Application& get_instance();

	protected:
		Application();
		~Application() = default;
		Application(const Application&) = delete;
		Application(Application&&) noexcept = delete;
		Application& operator = (Application&&) = delete;
		Application& operator = (const Application&) = delete;

		std::unordered_map<std::string_view, bool> _boolean_inputs;
		std::unordered_map<std::string_view, size_t> _size_t_inputs;
		std::unordered_map<std::string_view, double> _double_inputs;
		std::unordered_map<std::string_view, std::string> _string_inputs;

		CLI::App _application;
		std::unordered_map<std::string, std::pair<CLI::App*, std::function<bool()>>> _commands;

		bool _setup_view_command();
		
		bool _setup_generate_command();

		bool _setup_encrypt_command();

		bool _setup_decrypt_command();
		
		bool _setup_hash_command();

		bool _setup_verify_command();

		bool _setup_run_command();

		bool _setup_build_command();

		bool _setup_get_command();

		bool _setup_set_command();

		bool _setup_setup_command();

		bool _setup_deploy_command();
	};
}
