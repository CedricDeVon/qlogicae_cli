#pragma once

#include "pch.hpp"

#include "globals.hpp"

namespace QLogicaeCLI
{
	class QLogicaeCLIApplication
	{
	public:
		bool parse();
		bool setup(int, char**);
	
		static QLogicaeCLIApplication& get_instance();

	protected:
		QLogicaeCLIApplication();
		~QLogicaeCLIApplication() = default;
		QLogicaeCLIApplication(const QLogicaeCLIApplication&) = delete;
		QLogicaeCLIApplication(QLogicaeCLIApplication&&) noexcept = delete;
		QLogicaeCLIApplication& operator = (QLogicaeCLIApplication&&) = delete;
		QLogicaeCLIApplication& operator = (const QLogicaeCLIApplication&) = delete;

		size_t _generate_uuid4_input_1;
		std::string _generate_uuid4_input_2;
		bool _generate_uuid4_input_3;
		bool _generate_uuid4_input_4;

		size_t _generate_string_input_1;
		size_t _generate_string_input_2;
		std::string _generate_string_input_3;
		std::string _generate_string_input_4;
		bool _generate_string_input_5;
		bool _generate_string_input_6;

		std::string _encrypt_xchacha20poly1305_input_1;
		std::string _encrypt_xchacha20poly1305_input_2;
		std::string _encrypt_xchacha20poly1305_input_3;
		std::string _encrypt_xchacha20poly1305_input_4;
		bool _encrypt_xchacha20poly1305_input_5;
		bool _encrypt_xchacha20poly1305_input_6;

		std::string _decrypt_xchacha20poly1305_input_1;
		std::string _decrypt_xchacha20poly1305_input_2;
		std::string _decrypt_xchacha20poly1305_input_3;
		std::string _decrypt_xchacha20poly1305_input_4;
		bool _decrypt_xchacha20poly1305_input_5;
		bool _decrypt_xchacha20poly1305_input_6;

		std::string _hash_argon2id_input_1;
		std::string _hash_argon2id_input_2;
		bool _hash_argon2id_input_3;
		bool _hash_argon2id_input_4;

		std::string _verify_argon2id_input_1;
		std::string _verify_argon2id_input_2;
		std::string _verify_argon2id_input_3;
		bool _verify_argon2id_input_4;
		bool _verify_argon2id_input_5;

		std::vector<std::string> _run_scripts_input_1;
		std::string _run_scripts_input_2;
		bool _run_scripts_input_3;

		std::string _set_environment_input_1;
		std::string _set_environment_input_2;
		bool _set_environment_input_3;

		std::string _view_windows_registry_input_1;
		bool _view_windows_registry_input_2;

		std::string _setup_windows_registry_input_1;
		std::string _setup_windows_registry_input_2;
		std::string _setup_windows_registry_input_3;
		std::string _setup_windows_registry_input_4;
		bool _setup_windows_registry_input_5;

		std::string _setup_default_template_input_1;
		bool _setup_default_template_input_2;

		std::string _verify_default_template_input_1;
		bool _verify_default_template_input_2;

		std::string _setup_installer_input_1;
		std::string _setup_installer_input_2;
		bool _setup_installer_input_3;

		CLI::App _application;
		std::unordered_map<std::string, std::pair<CLI::App*, std::function<bool()>>> _commands;

		bool _setup_about_command();
		bool _setup_generate_uuid4_command();
		bool _setup_generate_string_command();
		bool _setup_encrypt_xchacha20poly1305_command();
		bool _setup_decrypt_xchacha20poly1305_command();
		bool _setup_hash_argon2id_command();
		bool _setup_verify_argon2id_command();
		bool _setup_run_scripts_command();
		bool _setup_set_environment_command();
		bool _setup_view_windows_registry_command();
		bool _setup_setup_windows_registry_command();
		bool _setup_setup_default_template_command();
		bool _setup_verify_default_template_command();
		bool _setup_setup_installer_command();

		void _log_running_timestamp(const bool& is_enabled = true);
		void _log_complete_timestamp(const bool& is_enabled = true);
		void _log_info_timestamp(
			const std::string& text, const bool& is_enabled = true);
		void _log_success_timestamp(
			const std::string& text, const bool& is_enabled = true);
		void _log_warning_timestamp(
			const std::string& text, const bool& is_enabled = true);
		void _log_exception_timestamp(
			const std::string& text, const bool& is_enabled = true);

		void _log_running_timestamp_async(const bool& is_enabled = true);
		void _log_complete_timestamp_async(const bool& is_enabled = true);
		void _log_info_timestamp_async(
			const std::string& text, const bool& is_enabled = true);
		void _log_success_timestamp_async(
			const std::string& text, const bool& is_enabled = true);
		void _log_warning_timestamp_async(
			const std::string& text, const bool& is_enabled = true);
		void _log_exception_timestamp_async(
			const std::string& text, const bool& is_enabled = true);

		std::string _transform_log_running_timestamp(
			const bool& is_enabled = true);
		std::string _transform_log_complete_timestamp(
			const bool& is_enabled = true);
		std::string _transform_log_info_timestamp(
			const std::string& text = "", const bool& is_enabled = true);
		std::string _transform_log_success_timestamp(
			const std::string& text = "", const bool& is_enabled = true);
		std::string _transform_log_warning_timestamp(
			const std::string& text = "", const bool& is_enabled = true);
		std::string _transform_log_exception_timestamp(
			const std::string& text = "", const bool& is_enabled = true);
	};
}

/*
						std::string output_string =
							_transform_log_running_timestamp(
								_verify_default_template_input_2
							);

						for (const auto& [key, value] : items)
						{
							output_string += key + "\t -> " + value;
							if (index_a++ < size_a)
							{
								output_string += "\n";
							}
						}
						output_string +=
							_transform_log_complete_timestamp(
								_verify_default_template_input_2
							);

						output_string +=
								_transform_log_exception_timestamp(
									"File '" + _set_environment_input_2 + "' does not exist"
								);
						QLogicaeCore::CLI_IO.print(output_string);

						QLogicaeCore::CLI_IO.print(output_string);
*/