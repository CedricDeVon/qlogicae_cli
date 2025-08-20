#pragma once

#include "pch.hpp"

#include "application.hpp"

using namespace QLogicaeCore;

namespace QLogicaeCLI
{
	QLogicaeCLIApplication::QLogicaeCLIApplication() :
		_application(
			QLogicaeCLI::application_full_name
		)
	{
	}

	bool QLogicaeCLIApplication::setup(int argc, char** argv)
	{
		try
		{
			if (!_setup_about_command() ||
				!_setup_generate_uuid4_command() ||
				!_setup_generate_string_command() ||
				!_setup_encrypt_xchacha20poly1305_command() ||
				!_setup_decrypt_xchacha20poly1305_command() ||
				!_setup_hash_argon2id_command() ||
				!_setup_verify_argon2id_command() ||
				!_setup_run_scripts_command() ||
				!_setup_set_environment_command() ||
				!_setup_view_windows_registry_command() ||
				!_setup_setup_windows_registry_command() ||
				!_setup_setup_default_template_command() ||
				!_setup_verify_default_template_command() ||
				!_setup_setup_installer_command())
			{
				return false;
			}

			CLI11_PARSE(_application, argc, argv);
		}
		catch (const std::exception& exception)
		{
			_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::setup(): ") + exception.what());

			return false;
		}

		return true;
	}

	bool QLogicaeCLIApplication::parse()
	{
		try
		{
			for (const auto& [key, value] : _commands)
			{
				if (value.first->parsed())
				{
					return value.second();
				}
			}
		}
		catch (const std::exception& exception)
		{
			_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::parse(): ") + exception.what());

			return false;
		}

		return true;
	}

	QLogicaeCLIApplication& QLogicaeCLIApplication::get_instance()
	{
		static QLogicaeCLIApplication singleton;

		return singleton;
	}

	bool QLogicaeCLIApplication::_setup_about_command()
	{
		try
		{
			std::string command_name = "about";
			_commands[command_name] = std::make_pair(
				_application.add_subcommand(
					command_name, ""),
				[this]() -> bool
				{
					QLogicaeCore::CLI_IO.print(application_full_name);

					return true;
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_about_command(): ") + exception.what());

			return false;
		}
	}

	bool QLogicaeCLIApplication::_setup_generate_uuid4_command()
	{
		try
		{
			std::string command_name = "generate-uuid4";
			_commands[command_name] = std::make_pair(
				_application.add_subcommand(
					command_name, ""),
				[this]() -> bool
				{
					try
					{
						_log_running_timestamp_async(_generate_uuid4_input_3);

						if (!_generate_uuid4_input_1)
						{
							return false;
						}

						std::string output_string = "";
						size_t index_1, size_a = _generate_uuid4_input_1 - 1;

						for (index_1 = 0;
							index_1 < _generate_uuid4_input_1;
							++index_1)
						{
							output_string += QLogicaeCore::GENERATOR.random_uuid4();
							if (index_1 < size_a)
							{
								output_string += "\n";
							}
						}

						QLogicaeCore::CLI_IO.print_with_new_line_async(
							output_string
						);

						if (_generate_uuid4_input_4)
						{
							text_file_io.set_file_path(_generate_uuid4_input_2);
							text_file_io.write_async(output_string);
						}

						_log_complete_timestamp_async(_generate_uuid4_input_3);
					}
					catch (const std::exception exception)
					{
						_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_generate_uuid4_command(): ") + exception.what(), _generate_uuid4_input_3);

						return false;
					}

					return true;
				}
			);
			_commands[command_name].first
				->add_option("--count",
					_generate_uuid4_input_1,
					"")
				->check(CLI::NonNegativeNumber)
				->default_val(1);
			_commands[command_name].first
				->add_option("--output-file-path",
					_generate_uuid4_input_2,
					"")
				->default_val("");
			_commands[command_name].first
				->add_option("--is-file-output-enabled",
					_generate_uuid4_input_4,
					"")
				->default_val(false);
			_commands[command_name].first
				->add_option("--is-verbose-logging-enabled",
					_generate_uuid4_input_3,
					"")
				->default_val(true);

			return true;
		}
		catch (const std::exception& exception)
		{
			_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_generate_uuid4_command(): ") + exception.what(), _generate_uuid4_input_3);

			return false;
		}
	}

	bool QLogicaeCLIApplication::_setup_generate_string_command()
	{
		try
		{
			std::string command_name = "generate-string";
			_commands[command_name] = std::make_pair(
				_application.add_subcommand(
					command_name, ""),
				[this]() -> bool
				{
					try
					{
						_log_running_timestamp_async(_generate_string_input_5);

						if (!_generate_string_input_1 ||
							!_generate_string_input_2)
						{
							return false;
						}

						size_t index_1, size_a = _generate_string_input_2 - 1;
						std::string output_string = "",
							character_set = (_generate_string_input_3.empty()) ?
							QLogicaeCore::Constants::FULL_VISIBLE_ASCII_CHARACTERSET.data() :
							_generate_string_input_3;
						
						for (index_1 = 0;
							index_1 < _generate_string_input_2;
							++index_1)
						{
							output_string += QLogicaeCore::GENERATOR.random_string(
								_generate_string_input_1,
								character_set
							);
							if (index_1 < size_a)
							{
								output_string += "\n";
							}
						}

						QLogicaeCore::CLI_IO.print_with_new_line_async(
							output_string
						);

						if (_generate_string_input_6)
						{
							text_file_io.set_file_path(_generate_string_input_4);
							text_file_io.write_async(output_string);
						}

						_log_complete_timestamp_async(_generate_string_input_5);
					}
					catch (const std::exception exception)
					{
						_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_generate_string_command(): ") + exception.what(), _generate_string_input_5);

						return false;
					}

					return true;
				}
			);
			_commands[command_name].first
				->add_option("--length",
					_generate_string_input_1,
					"")
				->check(CLI::NonNegativeNumber)
				->default_val(32);
			_commands[command_name].first
				->add_option("--count",
					_generate_string_input_2,
					"")
				->check(CLI::NonNegativeNumber)
				->default_val(1);
			_commands[command_name].first
				->add_option("--character-set",
					_generate_string_input_3,
					"")
				->default_val("");
			_commands[command_name].first
				->add_option("--output-file-path",
					_generate_string_input_4,
					"")
				->default_val("");
			_commands[command_name].first
				->add_option("--is-file-output-enabled",
					_generate_string_input_6,
					"")
				->default_val(false);
			_commands[command_name].first
				->add_option("--is-verbose-logging-enabled",
					_generate_string_input_5,
					"")
				->default_val(true);

			return true;
		}
		catch (const std::exception& exception)
		{
			_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_generate_string_command(): ") + exception.what(), _generate_string_input_5);

			return false;
		}
	}

	bool QLogicaeCLIApplication::_setup_encrypt_xchacha20poly1305_command()
	{
		try
		{
			std::string command_name = "encrypt-xchacha20poly1305";
			_commands[command_name] = std::make_pair(
				_application.add_subcommand(
					command_name, ""),
				[this]() -> bool
				{
					try
					{
						_log_running_timestamp_async(_encrypt_xchacha20poly1305_input_5);

						if (_encrypt_xchacha20poly1305_input_3.empty())
						{
							_encrypt_xchacha20poly1305_input_3 =
								QLogicaeCore::GENERATOR.random_string(24);
						}

						std::string output_string =
							cryptographer_1.transform(
								_encrypt_xchacha20poly1305_input_1,
								_encrypt_xchacha20poly1305_input_2,
								_encrypt_xchacha20poly1305_input_3
							) + "\n" +
							_encrypt_xchacha20poly1305_input_3;

						QLogicaeCore::CLI_IO.print_with_new_line_async(
							output_string
						);

						if (_encrypt_xchacha20poly1305_input_6)
						{
							text_file_io.set_file_path(_encrypt_xchacha20poly1305_input_4);
							text_file_io.write_async(output_string);
						}

						_log_complete_timestamp_async(_encrypt_xchacha20poly1305_input_5);
					}
					catch (const std::exception exception)
					{
						_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_encrypt_xchacha20poly1305_command(): ") + exception.what(), _encrypt_xchacha20poly1305_input_5);

						return false;
					}

					return true;
				}
			);
			_commands[command_name].first
				->add_option("--text",
					_encrypt_xchacha20poly1305_input_1,
					"")
				->required();
			_commands[command_name].first
				->add_option("--key",
					_encrypt_xchacha20poly1305_input_2,
					"")
				->required();
			_commands[command_name].first
				->add_option("--nonce",
					_encrypt_xchacha20poly1305_input_3,
					"")
				->default_val(QLogicaeCore::GENERATOR.random_string(24));
			_commands[command_name].first
				->add_option("--output-file-path",
					_encrypt_xchacha20poly1305_input_4,
					"")
				->default_val("");
			_commands[command_name].first
				->add_option("--is-file-output-enabled",
					_encrypt_xchacha20poly1305_input_6,
					"")
				->default_val(true);
			_commands[command_name].first
				->add_option("--is-verbose-logging-enabled",
					_encrypt_xchacha20poly1305_input_5,
					"")
				->default_val(true);

			return true;
		}
		catch (const std::exception& exception)
		{
			_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_encrypt_xchacha20poly1305_command(): ") + exception.what(), _encrypt_xchacha20poly1305_input_5);

			return false;
		}
	}

	bool QLogicaeCLIApplication::_setup_decrypt_xchacha20poly1305_command()
	{
		try
		{
			std::string command_name = "decrypt-xchacha20poly1305";
			_commands[command_name] = std::make_pair(
				_application.add_subcommand(
					command_name, ""),
				[this]() -> bool
				{
					try
					{
						_log_running_timestamp_async(_decrypt_xchacha20poly1305_input_5);

						std::string output_string =
							cryptographer_1.reverse(
								_decrypt_xchacha20poly1305_input_1,
								_decrypt_xchacha20poly1305_input_2,
								_decrypt_xchacha20poly1305_input_3
							);

						QLogicaeCore::CLI_IO.print_with_new_line_async(
							output_string
						);
						
						if (_decrypt_xchacha20poly1305_input_6)
						{
							text_file_io.set_file_path(_decrypt_xchacha20poly1305_input_4);
							text_file_io.write_async(output_string);
						}

						_log_complete_timestamp_async(_decrypt_xchacha20poly1305_input_5);
					}
					catch (const std::exception exception)
					{
						_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_decrypt_xchacha20poly1305_command(): ") + exception.what(), _decrypt_xchacha20poly1305_input_5);

						return false;
					}

					return true;
				}
			);
			_commands[command_name].first
				->add_option("--text",
					_decrypt_xchacha20poly1305_input_1,
					"")
				->required();
			_commands[command_name].first
				->add_option("--key",
					_decrypt_xchacha20poly1305_input_2,
					"")
				->required();
			_commands[command_name].first
				->add_option("--nonce",
					_decrypt_xchacha20poly1305_input_3,
					"")
				->required();
			_commands[command_name].first
				->add_option("--output-file-path",
					_decrypt_xchacha20poly1305_input_4,
					"")
				->default_val("");
			_commands[command_name].first
				->add_option("--is-file-output-enabled",
					_decrypt_xchacha20poly1305_input_6,
					"")
				->default_val(false);
			_commands[command_name].first
				->add_option("--is-verbose-logging-enabled",
					_decrypt_xchacha20poly1305_input_5,
					"")
				->default_val(true);

			return true;
		}
		catch (const std::exception& exception)
		{
			_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_decrypt_xchacha20poly1305_command(): ") + exception.what(), _decrypt_xchacha20poly1305_input_5);

			return false;
		}
	}

	bool QLogicaeCLIApplication::_setup_hash_argon2id_command()
	{
		try
		{
			std::string command_name = "hash-argon2id";
			_commands[command_name] = std::make_pair(
				_application.add_subcommand(
					command_name, ""),
				[this]() -> bool
				{
					try
					{
						_log_running_timestamp_async(_hash_argon2id_input_3);

						std::string output_string =
							cryptographer_3.transform(
								_hash_argon2id_input_1
							);

						if (_hash_argon2id_input_3)
						{
							QLogicaeCore::CLI_IO.print_with_new_line_async(
								output_string
							);
						}

						if (_hash_argon2id_input_4)
						{
							text_file_io.set_file_path(_hash_argon2id_input_2);
							text_file_io.write_async(output_string);
						}

						_log_complete_timestamp_async(_hash_argon2id_input_3);
					}
					catch (const std::exception exception)
					{
						_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_hash_argon2id_command(): ") + exception.what(), _hash_argon2id_input_3);

						return false;
					}

					return true;
				}
			);
			_commands[command_name].first
				->add_option("--text",
					_hash_argon2id_input_1,
					"")
				->required();
			_commands[command_name].first
				->add_option("--output-file-path",
					_hash_argon2id_input_2,
					"")
				->default_val("");
			_commands[command_name].first
				->add_option("--is-file-output-enabled",
					_hash_argon2id_input_4,
					"")
				->default_val(false);
			_commands[command_name].first
				->add_option("--is-verbose-logging-enabled",
					_hash_argon2id_input_3,
					"")
				->default_val(true);

			return true;
		}
		catch (const std::exception& exception)
		{
			_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_hash_argon2id_command(): ") + exception.what(), _hash_argon2id_input_3);

			return false;
		}
	}

	bool QLogicaeCLIApplication::_setup_verify_argon2id_command()
	{
		try
		{
			std::string command_name = "verify-argon2id";
			_commands[command_name] = std::make_pair(
				_application.add_subcommand(
					command_name, ""),
				[this]() -> bool
				{
					try
					{
						_log_running_timestamp_async(_verify_argon2id_input_4);

						std::string output_string =
							(cryptographer_3.reverse(
								_verify_argon2id_input_1,
								_verify_argon2id_input_2
							)) ? "true" : "false";

						if (_verify_argon2id_input_4)
						{
							QLogicaeCore::CLI_IO.print_with_new_line_async(
								output_string
							);
						}

						if (_verify_argon2id_input_5)
						{
							text_file_io.set_file_path(_verify_argon2id_input_3);
							text_file_io.write_async(output_string);
						}

						_log_complete_timestamp_async(_verify_argon2id_input_4);
					}
					catch (const std::exception exception)
					{
						_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_verify_argon2id_command(): ") + exception.what(), _verify_argon2id_input_4);

						return false;
					}

					return true;
				}
			);
			_commands[command_name].first
				->add_option("--hash",
					_verify_argon2id_input_1,
					"")
				->required();
			_commands[command_name].first
				->add_option("--key",
					_verify_argon2id_input_2,
					"")
				->required();
			_commands[command_name].first
				->add_option("--output-file-path",
					_verify_argon2id_input_3,
					"")
				->default_val("");
			_commands[command_name].first
				->add_option("--is-file-output-enabled",
					_verify_argon2id_input_5,
					"")
				->default_val(false);
			_commands[command_name].first
				->add_option("--is-verbose-logging-enabled",
					_verify_argon2id_input_4,
					"")
				->default_val(true);

			return true;
		}
		catch (const std::exception& exception)
		{
			_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_verify_argon2id_command(): ") + exception.what(), _verify_argon2id_input_4);

			return false;
		}
	}

	bool QLogicaeCLIApplication::_setup_run_scripts_command()
	{
		try
		{
			std::string command_name = "run-scripts";
			_commands[command_name] = std::make_pair(
				_application.add_subcommand(
					command_name, ""),
				[this]() -> bool
				{
					try
					{
						_log_running_timestamp_async(_run_scripts_input_3);

						if (_run_scripts_input_1.empty() ||
							_run_scripts_input_2.empty())
						{
							return false;
						}

						client_utilities_file.set_file_path(
							_run_scripts_input_2
						);
						std::unordered_map<std::string, std::any> scripts =
							client_utilities_file.get_object({ "scripts" }
							);
						for (const std::string script_command :
						_run_scripts_input_1)
						{
							if (scripts.contains(script_command))
							{
								system(std::any_cast<std::string>(
									scripts[script_command]
								).c_str());
							}
							else
							{
								_log_warning_timestamp_async(
									"Script '" + script_command +
									"' does not exist",
									_run_scripts_input_3
								);
							}
						}

						_log_complete_timestamp_async(_run_scripts_input_3);
					}
					catch (const std::exception& exception)
					{
						_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_run_scripts_command(): ") + exception.what(), _run_scripts_input_3);

						return false;
					}

					return true;
				}
			);
			_commands[command_name].first
				->add_option("--names",
					_run_scripts_input_1,
					"")
				->delimiter(',')
				->required();
			_commands[command_name].first
				->add_option("--utilities-file-path",
					_run_scripts_input_2,
					"")
				->default_val(
					std::filesystem::path(
						configurations_folder_name /
						utilities_file_name
					).string()
				);
			_commands[command_name].first
				->add_option("--is-verbose-logging-enabled",
					_run_scripts_input_3,
					"")
				->default_val(true);

			return true;
		}
		catch (const std::exception& exception)
		{
			_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_run_scripts_command(): ") + exception.what(), _run_scripts_input_3);

			return false;
		}

	}

	bool QLogicaeCLIApplication::_setup_set_environment_command()
	{
		try
		{
			std::string command_name = "set-environment";
			_commands[command_name] = std::make_pair(
				_application.add_subcommand(
					command_name, ""),
				[this]() -> bool
				{
					try
					{
						_log_running_timestamp_async(_set_environment_input_3);

						if (_set_environment_input_1.empty() ||
							_set_environment_input_2.empty())
						{
							return false;
						}
						
						if (!std::filesystem::exists(
								_set_environment_input_2
							))
						{
							_log_exception_timestamp_async(
								"File '" + _set_environment_input_2 + "' does not exist"
							);

							return false;
						}

						client_utilities_file.set_file_path(
							_set_environment_input_2
						);
						client_utilities_file.update_string(
							{ "environment", "selected" },
							_set_environment_input_1
						);

						_log_complete_timestamp_async(_set_environment_input_3);
					}
					catch (const std::exception& exception)
					{
						_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_set_environment_command(): ") + exception.what(), _set_environment_input_3);

						return false;
					}

					return true;
				}
			);
			_commands[command_name].first
				->add_option("--type",
					_set_environment_input_1,
					"")
				->check(CLI::IsMember(utilities_environment_types))
				->default_val("development");
			_commands[command_name].first
				->add_option("--utilities-file-path",
					_set_environment_input_2,
					"")
				->default_val(
					std::filesystem::path(
						configurations_folder_name / utilities_file_name
					).string()
				);
			_commands[command_name].first
				->add_option("--is-verbose-logging-enabled",
					_set_environment_input_3,
					"")
				->default_val(true);

			return true;
		}
		catch (const std::exception& exception)
		{
			_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_set_environment_command(): ") + exception.what(), _set_environment_input_3);

			return false;
		}

	}

	bool QLogicaeCLIApplication::_setup_view_windows_registry_command()
	{
		try
		{
			std::string command_name = "view-windows-registry";
			_commands[command_name] = std::make_pair(
				_application.add_subcommand(
					command_name, ""),
				[this]() -> bool
				{
					try
					{
						_log_running_timestamp_async(_view_windows_registry_input_2);

						if (_view_windows_registry_input_1.empty())
						{
							return false;
						}

						std::string output_string = "";
						std::unordered_map<std::string, std::string> items =
							QLogicaeCore::WINDOWS_REGISTRY_HKCU.get_values_via_utf8(
								_view_windows_registry_input_1
							);
						size_t index_a = 0, size_a = items.size() - 1;

						for (const auto& [key, value] : items)
						{
							output_string += key + " -> " + value + "\n";
						}
						QLogicaeCore::CLI_IO.print_async(output_string);
						
						_log_complete_timestamp_async(_view_windows_registry_input_2);
					}
					catch (const std::exception& exception)
					{
						_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_view_windows_registry_command(): ") + exception.what(), _view_windows_registry_input_2);

						return false;
					}

					return true;
				}
			);
			_commands[command_name].first
				->add_option("--sub-path",
					_view_windows_registry_input_1,
					"")
				->default_val("")
				->required();
			_commands[command_name].first
				->add_option("--is-verbose-logging-enabled",
					_view_windows_registry_input_2,
					"")
				->default_val(true);

			return true;
		}
		catch (const std::exception& exception)
		{
			_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_view_windows_registry_command(): ") + exception.what(), _view_windows_registry_input_2);

			return false;
		}
	}

	bool QLogicaeCLIApplication::_setup_setup_windows_registry_command()
	{
		try
		{
			std::string command_name = "setup-windows-registry";
			_commands[command_name] = std::make_pair(
				_application.add_subcommand(
					command_name,
					""),
				[this]() -> bool
				{
					try
					{
						_log_running_timestamp_async(_setup_windows_registry_input_5);

						if (_setup_windows_registry_input_1.empty() ||
							_setup_windows_registry_input_2.empty() ||
							_setup_windows_registry_input_3.empty() ||
							_setup_windows_registry_input_4.empty())
						{
							return false;
						}

						if (!std::filesystem::exists(_setup_windows_registry_input_2))
						{
							_log_exception_timestamp_async(
								"File path '" + _setup_windows_registry_input_2 + "' does not exist"
							);

							return false;
						}
						if (!std::filesystem::exists(_setup_windows_registry_input_3))
						{
							_log_exception_timestamp_async(
								"File path '" + _setup_windows_registry_input_3 + "' does not exist"							
							);

							return false;
						}
						if (!std::filesystem::exists(_setup_windows_registry_input_4))
						{
							_log_exception_timestamp_async(
								"File path '" + _setup_windows_registry_input_4 + "' does not exist"
							);

							return false;
						}

						client_public_file.set_file_path(
							_setup_windows_registry_input_2
						);
						client_utilities_file.set_file_path(
							_setup_windows_registry_input_3
						);
						client_private_file.set_file_path(
							_setup_windows_registry_input_4
						);

						std::string client_id =
							client_public_file.get_string(
								{ "application", "id" }
							);
						if (_setup_windows_registry_input_1 == "all")
						{
							for (const std::string& environment_type : utilities_environment_types)
							{
								std::string environment_id =
									client_utilities_file.get_string(
										{ "environment", "selections",
										environment_type }
									);
								std::unordered_map<std::string, std::any>
									hkcu_secrets =
									client_private_file.get_object(
										{
											"windows_registry",
											environment_type,
											"hkcu"
										}
									);
								std::unordered_map<std::string, std::any>
									is_root_key_used =
									client_private_file.get_object(
										{ "windows_registry", "is_root_key_used" }
									);

								if (std::any_cast<bool>(is_root_key_used["hkcu"]))
								{
									for (const auto& [key, value] : hkcu_secrets)
									{
										QLogicaeCore::WINDOWS_REGISTRY_HKCU
											.set_value_via_utf8(
												absl::StrCat("Software",
													"\\",
													client_id,
													"\\",
													environment_id
												),
												key,
												std::any_cast<std::string>(value)
											);
									}
								}
								else
								{
									_log_warning_timestamp_async(
										"HKCU windows registry setup is disabled. Instruction skipped"
									);
								}
							}
						}
						else
						{
							std::string environment_id =
								client_utilities_file.get_string(
									{ "environment", "selections",
									_setup_windows_registry_input_1 }
								);
							std::unordered_map<std::string, std::any>
								hkcu_secrets =
								client_private_file.get_object(
									{
										"windows_registry",
										_setup_windows_registry_input_1,
										"hkcu"
									}
								);
							std::unordered_map<std::string, std::any>
								is_root_key_used =
								client_private_file.get_object(
									{ "windows_registry", "is_root_key_used" }
								);

							if (std::any_cast<bool>(is_root_key_used["hkcu"]))
							{
								for (const auto& [key, value] : hkcu_secrets)
								{
									QLogicaeCore::WINDOWS_REGISTRY_HKCU
										.set_value_via_utf8(
											fmt::format("Software\\{}\\{}",
												client_id,
												environment_id
											),
											key,
											std::any_cast<std::string>(value)
										);
								}
							}
							else
							{
								_log_warning_timestamp_async(
									"HKCU windows registry setup is disabled. Instruction skipped"
								);
							}
						}

						_log_complete_timestamp_async(_setup_windows_registry_input_5);
					}
					catch (const std::exception& exception)
					{
						_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_setup_windows_registry_command(): ") + exception.what(), _setup_windows_registry_input_5);

						return false;
					}

					return true;
				}
			);
			_commands[command_name].first
				->add_option(
					"--environment-type",
					_setup_windows_registry_input_1, "")
				->check(CLI::IsMember(utilities_environment_types_options)
				)
				->default_val("development")
				->required();
			_commands[command_name].first
				->add_option(
					"--public-file-path",
					_setup_windows_registry_input_2, "")
				->default_val(
					std::filesystem::path(
						configurations_folder_name /
						public_file_name
					).string()
				);
			_commands[command_name].first
				->add_option(
					"--utilities-file-path",
					_setup_windows_registry_input_3, "")
				->default_val(
					std::filesystem::path(
						configurations_folder_name /
						utilities_file_name
					).string()
				);
			_commands[command_name].first
				->add_option(
					"--private-file-path",
					_setup_windows_registry_input_4, "")
				->default_val(
					std::filesystem::path(
						private_file_name
					).string()
				);
			_commands[command_name].first
				->add_option("--is-verbose-logging-enabled",
					_setup_windows_registry_input_5,
					"")
				->default_val(true);

			return true;
		}
		catch (const std::exception& exception)
		{
			_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_setup_windows_registry_command(): ") + exception.what(), _setup_windows_registry_input_5);

			return false;
		}
	}

	bool QLogicaeCLIApplication::_setup_setup_default_template_command()
	{
		try
		{
			std::string command_name = "setup-default-template";
			_commands[command_name] = std::make_pair(
				_application.add_subcommand(
					command_name, ""),
				[this]() -> bool
				{
					try
					{
						if (_setup_default_template_input_1.empty())
						{
							return false;
						}

						_log_running_timestamp_async(_setup_default_template_input_2);

						if (!std::filesystem::exists(
							_setup_default_template_input_1 /
							configurations_folder_name
						))
						{
							std::filesystem::create_directory(
								_setup_default_template_input_1 /
								configurations_folder_name
							);
							_log_info_timestamp_async(
								fmt::format("Folder '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										configurations_folder_name
									).string()
								)
							);
						}
						else
						{
							_log_warning_timestamp_async(
								fmt::format("Folder '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										configurations_folder_name
									).string()
								)
							);
						}

						if (!std::filesystem::exists(
							_setup_default_template_input_1 /
							assets_folder_name
						))
						{
							std::filesystem::create_directory(
								_setup_default_template_input_1 /
								assets_folder_name
							);
							_log_info_timestamp_async(
								fmt::format("Folder '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										assets_folder_name
									).string()
								)
							);
						}
						else
						{
							_log_warning_timestamp_async(
								fmt::format("Folder '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										assets_folder_name
									).string()
								)
							);
						}

						if (!std::filesystem::exists(
							_setup_default_template_input_1 /
							scripts_folder_name
						))
						{
							std::filesystem::create_directory(
								_setup_default_template_input_1 /
								scripts_folder_name
							);
							_log_info_timestamp_async(
								fmt::format("Folder '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										scripts_folder_name
									).string()
								)
							);
						}
						else
						{
							_log_warning_timestamp_async(
								fmt::format("Folder '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										scripts_folder_name
									).string()
								)
							);
						}

						if (!std::filesystem::exists(
							_setup_default_template_input_1 /
							configurations_folder_name /
							public_file_name
						))
						{
							std::filesystem::copy_file(
								application_directory /
								templates_folder_name /
								"default" /
								public_file_name,
								_setup_default_template_input_1 /
								configurations_folder_name /
								public_file_name,
								std::filesystem::copy_options::overwrite_existing
							);
							client_public_file.set_file_path(
								std::filesystem::path(
									_setup_default_template_input_1 /
									configurations_folder_name /
									public_file_name
								).string()
							);
							client_public_file.update_string(
								{ "application", "id" },
								QLogicaeCore::GENERATOR.random_uuid4()
							);

							_log_info_timestamp_async(
								fmt::format("File '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										configurations_folder_name /
										public_file_name
									).string()
								)
							);
						}
						else
						{
							_log_warning_timestamp_async(
								fmt::format("Folder '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										configurations_folder_name /
										public_file_name
									).string()
								)
							);
						}

						if (!std::filesystem::exists(
							_setup_default_template_input_1 /
							configurations_folder_name /
							utilities_file_name
						))
						{
							std::filesystem::copy_file(
								application_directory /
								templates_folder_name /
								"default" /
								utilities_file_name,
								_setup_default_template_input_1 /
								configurations_folder_name /
								utilities_file_name,
								std::filesystem::copy_options::overwrite_existing
							);
							client_utilities_file.set_file_path(
								std::filesystem::path(
									_setup_default_template_input_1 /
									configurations_folder_name /
									utilities_file_name
								).string()
							);
							client_utilities_file.update_string(
								{ "environment", "selections", "development" },
								QLogicaeCore::GENERATOR.random_uuid4()
							);
							client_utilities_file.update_string(
								{ "environment", "selections", "debug" },
								QLogicaeCore::GENERATOR.random_uuid4()
							);
							client_utilities_file.update_string(
								{ "environment", "selections", "test" },
								QLogicaeCore::GENERATOR.random_uuid4()
							);
							client_utilities_file.update_string(
								{ "environment", "selections", "release" },
								QLogicaeCore::GENERATOR.random_uuid4()
							);

							_log_info_timestamp_async(
								fmt::format("File '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										configurations_folder_name /
										utilities_file_name
									).string()
								)
							);
						}
						else
						{
							_log_warning_timestamp_async(
								fmt::format("File '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										configurations_folder_name /
										utilities_file_name
									).string()
								)
							);
						}

						if (!std::filesystem::exists(
							_setup_default_template_input_1 /
							private_file_name
						))
						{
							std::filesystem::copy_file(
								application_directory /
								templates_folder_name /
								"default" /
								private_file_name,
								_setup_default_template_input_1 /
								private_file_name,
								std::filesystem::copy_options::overwrite_existing
							);
							_log_info_timestamp_async(
								fmt::format("File '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										private_file_name
									).string()
								)
							);
						}
						else
						{
							_log_warning_timestamp_async(
								fmt::format("File '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										private_file_name
									).string()
								)
							);
						}

						if (!std::filesystem::exists(
							_setup_default_template_input_1 /
							gitignore_file_name
						))
						{
							std::filesystem::copy_file(
								application_directory /
								templates_folder_name /
								"default" /
								gitignore_file_name,
								_setup_default_template_input_1 /
								gitignore_file_name,
								std::filesystem::copy_options::overwrite_existing
							);
							_log_info_timestamp_async(
								fmt::format("File '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										gitignore_file_name
									).string()
								)
							);
						}
						else
						{
							_log_warning_timestamp_async(
								fmt::format("File '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										gitignore_file_name
									).string()
								)
							);
						}

						if (!std::filesystem::exists(
							_setup_default_template_input_1 /
							license_file_name
						))
						{
							std::filesystem::copy_file(
								application_directory /
								templates_folder_name /
								"default" /
								license_file_name,
								_setup_default_template_input_1 /
								license_file_name,
								std::filesystem::copy_options::overwrite_existing
							);
							_log_info_timestamp_async(
								fmt::format("File '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										license_file_name
									).string()
								)
							);
						}
						else
						{
							_log_warning_timestamp_async(
								fmt::format("File '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										license_file_name
									).string()
								)
							);
						}

						if (!std::filesystem::exists(
							_setup_default_template_input_1 /
							scripts_folder_name /
							inno_run_file_name
						))
						{
							std::filesystem::copy_file(
								application_directory /
								templates_folder_name /
								"default" /
								inno_run_file_name,
								_setup_default_template_input_1 /
								scripts_folder_name /
								inno_run_file_name,
								std::filesystem::copy_options::overwrite_existing
							);
							_log_info_timestamp_async(
								fmt::format("File '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										scripts_folder_name /
										inno_run_file_name
									).string()
								)
							);
						}
						else
						{
							_log_warning_timestamp_async(
								fmt::format("File '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										scripts_folder_name /
										inno_run_file_name
									).string()
								)
							);
						}

						if (!std::filesystem::exists(
							_setup_default_template_input_1 /
							scripts_folder_name /
							inno_setup_file_name
						))
						{
							std::filesystem::copy_file(
								application_directory /
								templates_folder_name /
								"default" /
								inno_setup_file_name,
								_setup_default_template_input_1 /
								scripts_folder_name /
								inno_setup_file_name,
								std::filesystem::copy_options::overwrite_existing
							);
							_log_info_timestamp_async(
								fmt::format("File '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										scripts_folder_name /
										inno_setup_file_name
									).string()
								)
							);
						}
						else
						{
							_log_warning_timestamp_async(
								fmt::format("File '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										scripts_folder_name /
										inno_setup_file_name
									).string()
								)
							);
						}

						if (!std::filesystem::exists(
							_setup_default_template_input_1 /
							assets_folder_name /
							icon_file_name
						))
						{
							std::filesystem::copy_file(
								application_directory /
								templates_folder_name /
								"default" /
								icon_file_name,
								_setup_default_template_input_1 /
								assets_folder_name /
								icon_file_name,
								std::filesystem::copy_options::overwrite_existing
							);
							_log_info_timestamp_async(
								fmt::format("File '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										assets_folder_name /
										icon_file_name
									).string()
								)
							);
						}
						else
						{
							_log_warning_timestamp_async(
								fmt::format("File '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										assets_folder_name /
										icon_file_name
									).string()
								)
							);
						}

						_log_complete_timestamp_async(_setup_default_template_input_2);
					}
					catch (const std::exception& exception)
					{
						_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_setup_default_template_command(): ") + exception.what(), _setup_default_template_input_2);

						return false;
					}

					return true;
				}
			);
			_commands[command_name].first
				->add_option("--target-root-project-directory", _setup_default_template_input_1, "")
				->default_val(".");
			_commands[command_name].first
				->add_option("--is-verbose-logging-enabled",
					_setup_default_template_input_2,
					"")
				->default_val(true);

			return true;
		}
		catch (const std::exception& exception)
		{
			_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_setup_default_template_command(): ") + exception.what(), _setup_default_template_input_2);

			return false;
		}
	}

	bool QLogicaeCLIApplication::_setup_verify_default_template_command()
	{
		try
		{
			std::string command_name = "verify-default-filesystem";
			_commands[command_name] = std::make_pair(
				_application.add_subcommand(
					command_name, ""),
				[this]() -> bool
				{
					try
					{
						_log_running_timestamp_async(_verify_default_template_input_2);

						if (_verify_default_template_input_1.empty())
						{
							return false;
						}

						std::string output_string = "";
						std::vector<std::string> file_paths =
						{
							_verify_default_template_input_1 +
								scripts_inno_run_file_path,
							_verify_default_template_input_1 +
								scripts_inno_setup_file_path,
							_verify_default_template_input_1 +
								configurations_public_file_path,
							_verify_default_template_input_1 +
								private_file_path,
							_verify_default_template_input_1 +
								license_file_path,
							_verify_default_template_input_1 +
								gitignore_file_path
						};

						for (const std::string& file_path : file_paths)
						{
							if (std::filesystem::exists(file_path))
							{
								output_string +=
									_transform_log_success_timestamp(
										"File '" + file_path + "' exists"
									);
							}
							else
							{
								output_string +=
									_transform_log_exception_timestamp(
										"File '" + file_path + "' does not exist"
									);
							}
						}
						QLogicaeCore::CLI_IO.print_async(output_string);

						_log_complete_timestamp_async(_verify_default_template_input_2);
					}
					catch (const std::exception& exception)
					{
						_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_verify_default_template_command(): ") + exception.what(), _verify_default_template_input_2);

						return false;
					}

					return true;
				}
			);
			_commands[command_name].first
				->add_option("--target-root-project-directory", _verify_default_template_input_1, "")
				->default_val(".");
			_commands[command_name].first
				->add_option("--is-verbose-logging-enabled",
					_verify_default_template_input_2,
					"")
				->default_val(true);

			return true;
		}
		catch (const std::exception& exception)
		{
			_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_verify_default_template_command(): ") + exception.what(), _verify_default_template_input_2);

			return false;
		}
	}

	bool QLogicaeCLIApplication::_setup_setup_installer_command()
	{
		try
		{
			std::string command_name = "setup-installer";
			_commands[command_name] = std::make_pair(
				_application.add_subcommand(
					command_name, ""),
				[this]() -> bool
				{
					try
					{
						_log_running_timestamp_async(_setup_installer_input_3);

						client_public_file.set_file_path(
							std::filesystem::path(
								_setup_installer_input_1 /
								configurations_folder_name /
								public_file_name
							).string()
						);
						client_private_file.set_file_path(
							std::filesystem::path(
								_setup_installer_input_1 /
								private_file_name
							).string()
						);
						client_inno_run_file.set_file_path(
							std::filesystem::path(
								_setup_installer_input_1 /
								scripts_folder_name /
								inno_run_file_name
							).string()
						);
						client_inno_setup_file.set_file_path(
							std::filesystem::path(
								_setup_installer_input_1 /
								scripts_folder_name /
								inno_setup_file_name
							).string()
						);
						client_inno_setup_target_file.set_file_path(
							std::filesystem::path(
								_setup_installer_input_1 /
								scripts_folder_name /
								inno_setup_target_file_name
							).string()
						);
						client_utilities_file.set_file_path(
							std::filesystem::path(
								_setup_installer_input_1 /
								configurations_folder_name /
								utilities_file_name
							).string()
						);

						std::filesystem::path input_folder_path =
							std::filesystem::absolute(
								client_utilities_file.get_string(
									{ "inno_setup", "input_folder_path" }
								)
							);
						std::filesystem::path output_folder_path =
							std::filesystem::absolute(
								client_utilities_file.get_string(
									{ "inno_setup", "output_folder_path" }
								)
							);

						client_utilities_file.set_file_path(
							std::filesystem::path(
								input_folder_path /
								configurations_folder_name /
								utilities_file_name
							).string()
						);
						client_utilities_file.update_string(
							{ "environment", "selected" }, "release"
						);
						client_utilities_file.set_file_path(
							std::filesystem::path(
								_setup_installer_input_1 /
								configurations_folder_name /
								utilities_file_name
							).string()
						);

						if (!std::filesystem::exists(
							_setup_installer_input_1 /
							scripts_folder_name
						))
						{
							std::filesystem::create_directory(
								_setup_installer_input_1 /
								scripts_folder_name
							);
						}

						if (std::filesystem::exists(
							_setup_installer_input_1 /
							scripts_folder_name /
							inno_setup_target_file_name)
							)
						{
							std::filesystem::remove(
								_setup_installer_input_1 /
								scripts_folder_name /
								inno_setup_target_file_name
							);
						}

						std::filesystem::copy_file(
							_setup_installer_input_1 /
							scripts_folder_name /
							inno_setup_file_name,
							_setup_installer_input_1 /
							scripts_folder_name /
							inno_setup_target_file_name,
							std::filesystem::copy_options::overwrite_existing
						);

						std::unordered_map<std::string, std::any> languages =
							client_utilities_file.get_object(
								{ "languages" }
							);
						client_inno_setup_target_file.append(
							"\n[Languages]\n"
						);
						for (const auto& [name, properties] : languages)
						{
							std::unordered_map<std::string, std::any> object =
								std::any_cast<std::unordered_map<
								std::string, std::any>>(properties);
							if (std::any_cast<bool>(object["is_enabled"]))
							{
								client_inno_setup_target_file.append(
									"Name: \"" + name +
									"\"; MessagesFile: \"" +
									std::any_cast<std::string>(
										object["message_file"]
									) + "\"\n"
								);
							}
						}

						std::unordered_map<std::string, std::any>
							hkcu_secrets =
							client_private_file.get_object(
								{
									"windows_registry",
									"release",
									"hkcu"
								}
							);
						std::string application_id =
							client_public_file
							.get_string(
								{
									"application",
									"id"
								}
							);
						std::string release_id =
							client_utilities_file
							.get_string(
								{
									"environment",
									"selections",
									"release"
								}
							);
						client_inno_setup_target_file.append(
							"\n[Registry]\n"
						);
						for (const auto& [key, value] : hkcu_secrets)
						{
							std::string command =
								"Root: HKCU; Subkey: \"Software\\" +
								application_id +
								"\\" + release_id +
								"\"; ValueType: string; ValueName: \"" +
								std::any_cast<std::string>(key) +
								"\"; ValueData: \"" +
								std::any_cast<std::string>(value) +
								"\"; Flags: uninsdeletekeyifempty\n";
							client_inno_setup_target_file.append(
								command
							);
						}

						system(
							("powershell -ExecutionPolicy Bypass -File \"" +
								std::filesystem::path(
									_setup_installer_input_1 /
									scripts_folder_name /
									inno_run_file_name
								).string() + "\""
								).c_str()
						);

						if (std::filesystem::exists(
							_setup_installer_input_1 /
							temporary_folder_name
						))
						{
							std::filesystem::remove_all(
								_setup_installer_input_1 /
								temporary_folder_name
							);
						}

						client_utilities_file.update_string(
							{ "environment", "selected" }, "development"
						);
						client_utilities_file.update_string(
							{ "environment", "selections", "development" },
							QLogicaeCore::GENERATOR.random_uuid4()
						);
						client_utilities_file.update_string(
							{ "environment", "selections", "debug" },
							QLogicaeCore::GENERATOR.random_uuid4()
						);
						client_utilities_file.update_string(
							{ "environment", "selections", "test" },
							QLogicaeCore::GENERATOR.random_uuid4()
						);
						client_utilities_file.update_string(
							{ "environment", "selections", "release" },
							QLogicaeCore::GENERATOR.random_uuid4()
						);
						client_public_file.update_string(
							{ "application", "id" },
							QLogicaeCore::GENERATOR.random_uuid4()
						);

						_log_complete_timestamp_async(_setup_installer_input_3);
					}
					catch (const std::exception& exception)
					{
						_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_setup_installer_command(): ") + exception.what(), _setup_installer_input_3);

						return false;
					}

					return true;
				}
			);
			_commands[command_name].first
				->add_option("--target-project-folder",
					_setup_installer_input_1,
					"")
				->default_val(".");
			_commands[command_name].first
				->add_option("--output-directory",
					_setup_installer_input_2,
					"")
				->default_val(".");
			_commands[command_name].first
				->add_option("--is-verbose-logging-enabled",
					_setup_installer_input_3,
					"")
				->default_val(true);

			return true;
		}
		catch (const std::exception& exception)
		{
			_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_setup_installer_command(): ") + exception.what(), _setup_installer_input_3);

			return false;
		}
	}

	void QLogicaeCLIApplication::_log_running_timestamp(const bool& is_enabled)
	{
		if (is_enabled)
		{
			QLogicaeCLI::timestamp_logger.log(
				"Running...", QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
			);
		}
	}

	void QLogicaeCLIApplication::_log_complete_timestamp(const bool& is_enabled)
	{
		if (is_enabled)
		{
			QLogicaeCLI::timestamp_logger.log(
				"Complete!", QLogicaeCore::LogLevel::SUCCESS
			);
		}
	}

	void QLogicaeCLIApplication::_log_info_timestamp(
		const std::string& text,
		const bool& is_enabled)
	{
		if (is_enabled)
		{
			QLogicaeCLI::timestamp_logger.log(
				text, QLogicaeCore::LogLevel::INFO
			);
		}
	}

	void QLogicaeCLIApplication::_log_success_timestamp(
		const std::string& text,
		const bool& is_enabled)
	{
		if (is_enabled)
		{
			QLogicaeCLI::timestamp_logger.log(
				text, QLogicaeCore::LogLevel::SUCCESS
			);
		}
	}

	void QLogicaeCLIApplication::_log_warning_timestamp(
		const std::string& text,
		const bool& is_enabled)
	{
		if (is_enabled)
		{
			QLogicaeCLI::timestamp_logger.log(
				text, QLogicaeCore::LogLevel::WARNING
			);
		}
	}

	void QLogicaeCLIApplication::_log_exception_timestamp(
		const std::string& text, const bool& is_enabled
	)
	{
		if (is_enabled)
		{
			QLogicaeCLI::timestamp_logger.log(
				text, QLogicaeCore::LogLevel::EXCEPTION
			);
		}
	}

	void QLogicaeCLIApplication::_log_running_timestamp_async(
		const bool& is_enabled)
	{
		if (is_enabled)
		{
			QLogicaeCLI::timestamp_logger.log_async(
				"Running...", QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
			);
		}
	}

	void QLogicaeCLIApplication::_log_complete_timestamp_async(
		const bool& is_enabled)
	{
		if (is_enabled)
		{
			QLogicaeCLI::timestamp_logger.log_async(
				"Complete!", QLogicaeCore::LogLevel::SUCCESS
			);
		}
	}

	void QLogicaeCLIApplication::_log_info_timestamp_async(
		const std::string& text,
		const bool& is_enabled)
	{
		if (is_enabled)
		{
			QLogicaeCLI::timestamp_logger.log_async(
				text, QLogicaeCore::LogLevel::INFO
			);
		}
	}

	void QLogicaeCLIApplication::_log_success_timestamp_async(
		const std::string& text,
		const bool& is_enabled)
	{
		if (is_enabled)
		{
			QLogicaeCLI::timestamp_logger.log_async(
				text, QLogicaeCore::LogLevel::SUCCESS
			);
		}
	}

	void QLogicaeCLIApplication::_log_warning_timestamp_async(
		const std::string& text,
		const bool& is_enabled)
	{
		if (is_enabled)
		{
			QLogicaeCLI::timestamp_logger.log_async(
				text, QLogicaeCore::LogLevel::WARNING
			);
		}
	}

	void QLogicaeCLIApplication::_log_exception_timestamp_async(
		const std::string& text, const bool& is_enabled
	)
	{
		if (is_enabled)
		{
			QLogicaeCLI::timestamp_logger.log_async(
				text, QLogicaeCore::LogLevel::EXCEPTION
			);
		}
	}

	std::string QLogicaeCLIApplication::_transform_log_running_timestamp(

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

	std::string QLogicaeCLIApplication::_transform_log_complete_timestamp(

		const bool& is_enabled)
	{
		if (is_enabled)
		{
			return QLogicaeCore::TRANSFORMER.to_log_format(
				"Complete!",
				QLogicaeCore::LogLevel::SUCCESS
			);
		}

		return "";
	}

	std::string QLogicaeCLIApplication::_transform_log_info_timestamp(
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

	std::string QLogicaeCLIApplication::_transform_log_success_timestamp(
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

	std::string QLogicaeCLIApplication::_transform_log_warning_timestamp(
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

	std::string QLogicaeCLIApplication::_transform_log_exception_timestamp(
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
}
