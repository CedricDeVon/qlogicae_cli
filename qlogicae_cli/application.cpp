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
				!_setup_setup_vs2022_application_command() ||
				!_setup_verify_vs2022_application_command() ||
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
					command_name,
					"Project and application details"),
				[this]() -> bool
				{
					std::string text =
						application_full_name + "\n\n" +
						"Description:\n" + application_description + "\n\n" +
						"Authors:\n" + application_authors + "\n\n" +
						"Repository:\n" + application_url;


					QLogicaeCore::CLI_IO.print(text);

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
					command_name, "Random uuid4 generation"),
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
					"The number of generated uuid4s")
				->check(CLI::NonNegativeNumber)
				->default_val(1);
			_commands[command_name].first
				->add_option("--output-file-path",
					_generate_uuid4_input_2,
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");
			_commands[command_name].first
				->add_option("--is-file-output-enabled",
					_generate_uuid4_input_4,
					"Enables or disables the option '--output-file-path'")
				->default_val(false);
			_commands[command_name].first
				->add_option("--is-verbose-logging-enabled",
					_generate_uuid4_input_3,
					"Enables or disables verbose console logging")
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
					command_name, "Random string generation"),
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
					"The character length of each individual string output")
				->check(CLI::NonNegativeNumber)
				->default_val(32);
			_commands[command_name].first
				->add_option("--count",
					_generate_string_input_2,
					"The number of generated string outputs")
				->check(CLI::NonNegativeNumber)
				->default_val(1);
			_commands[command_name].first
				->add_option("--character-set",
					_generate_string_input_3,
					"A string of characters where each individual character can possibly be found within each string output")
				->default_val("");
			_commands[command_name].first
				->add_option("--output-file-path",
					_generate_string_input_4,
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");
			_commands[command_name].first
				->add_option("--is-file-output-enabled",
					_generate_string_input_6,
					"Enables or disables the option '--output-file-path'")
				->default_val(false);
			_commands[command_name].first
				->add_option("--is-verbose-logging-enabled",
					_generate_string_input_5,
					"Enables or disables verbose console logging")
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
					command_name, "Text encryption via XChaCha20-Poly1305"),
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
					"The string input to be encrypted")
				->required();
			_commands[command_name].first
				->add_option("--key",
					_encrypt_xchacha20poly1305_input_2,
					"Encryption key")
				->required();
			_commands[command_name].first
				->add_option("--nonce",
					_encrypt_xchacha20poly1305_input_3,
					"Encryption nonce. WARNING: Nonces must be 32 characters long")
				->default_val(QLogicaeCore::GENERATOR.random_string(32, QLogicaeCore::Constants::ALPHA_NUMERIC_CHARACTERS));
			_commands[command_name].first
				->add_option("--output-file-path",
					_encrypt_xchacha20poly1305_input_4,
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");
			_commands[command_name].first
				->add_option("--is-file-output-enabled",
					_encrypt_xchacha20poly1305_input_6,
					"Enables or disables the option '--output-file-path'")
				->default_val(false);
			_commands[command_name].first
				->add_option("--is-verbose-logging-enabled",
					_encrypt_xchacha20poly1305_input_5,
					"Enables or disables verbose console logging")
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
					command_name, "Cipher decryption via XChaCha20-Poly1305"),
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
					"The string cipher to be decrypted")
				->required();
			_commands[command_name].first
				->add_option("--key",
					_decrypt_xchacha20poly1305_input_2,
					"Encryption key")
				->required();
			_commands[command_name].first
				->add_option("--nonce",
					_decrypt_xchacha20poly1305_input_3,
					"Encryption nonce. WARNING: Nonces must be 32 characters long")
				->required();
			_commands[command_name].first
				->add_option("--output-file-path",
					_decrypt_xchacha20poly1305_input_4,
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");
			_commands[command_name].first
				->add_option("--is-file-output-enabled",
					_decrypt_xchacha20poly1305_input_6,
					"Enables or disables the option '--output-file-path'")
				->default_val(false);
			_commands[command_name].first
				->add_option("--is-verbose-logging-enabled",
					_decrypt_xchacha20poly1305_input_5,
					"Enables or disables verbose console logging")
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
					command_name, "Text hashing via Argon2ID"),
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
					"The string text to be hashed")
				->required();
			_commands[command_name].first
				->add_option("--output-file-path",
					_hash_argon2id_input_2,
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");
			_commands[command_name].first
				->add_option("--is-file-output-enabled",
					_hash_argon2id_input_4,
					"Enables or disables the option '--output-file-path'")
				->default_val(false);
			_commands[command_name].first
				->add_option("--is-verbose-logging-enabled",
					_hash_argon2id_input_3,
					"Enables or disables verbose console logging")
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
					command_name, "Hash verification via Argon2ID"),
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
					"The string hash to be verified")
				->required();
			_commands[command_name].first
				->add_option("--key",
					_verify_argon2id_input_2,
					"The original text to be compared with the hash")
				->required();
			_commands[command_name].first
				->add_option("--output-file-path",
					_verify_argon2id_input_3,
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");
			_commands[command_name].first
				->add_option("--is-file-output-enabled",
					_verify_argon2id_input_5,
					"Enables or disables the option '--output-file-path'")
				->default_val(false);
			_commands[command_name].first
				->add_option("--is-verbose-logging-enabled",
					_verify_argon2id_input_4,
					"Enables or disables verbose console logging")
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
					command_name, "Extracts and executes command-line scripts"),
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

						client_private_file.set_file_path(
							_run_scripts_input_2
						);
						std::unordered_map<std::string, std::any> scripts =
							client_private_file.get_object({ "scripts" }
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
					"Selected script commands")
				->delimiter(',')
				->required();
			_commands[command_name].first
				->add_option("--private-file-path",
					_run_scripts_input_2,
					"File path to the 'qlogicae.private.json' file")
				->default_val(
					configurations_folder_name_string + "\\" + private_file_name_string
				);
			_commands[command_name].first
				->add_option("--is-verbose-logging-enabled",
					_run_scripts_input_3,
					"Enables or disables verbose console logging")
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
					command_name, "Changes the selected environment"),
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

						client_public_file.set_file_path(
							_set_environment_input_2
						);
						client_public_file.update_string(
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
					"Selected environment type")
				->check(CLI::IsMember(utilities_environment_types))
				->default_val("development");
			_commands[command_name].first
				->add_option("--public-file-path",
					_set_environment_input_2,
					"File path to the 'qlogicae.public.json' file")
				->default_val(
					configurations_folder_name_string + "\\" + private_file_name_string
				);
			_commands[command_name].first
				->add_option("--is-verbose-logging-enabled",
					_set_environment_input_3,
					"Enables or disables verbose console logging")
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
					command_name,
					"Displays the key-value pairs of a selected Windows Registry path"),
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
					"Windows Registry path")
				->default_val("")
				->required();
			_commands[command_name].first
				->add_option("--is-verbose-logging-enabled",
					_view_windows_registry_input_2,
					"Enables or disables verbose console logging")
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
					"Creates or updates the key-value pairs of a selected Windows Registry path"),
				[this]() -> bool
				{
					try
					{
						_log_running_timestamp_async(_setup_windows_registry_input_5);

						if (_setup_windows_registry_input_1.empty() ||
							_setup_windows_registry_input_2.empty() ||
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
									client_public_file.get_string(
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
								client_public_file.get_string(
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
					_setup_windows_registry_input_1,
					"Selected environment type")
				->check(CLI::IsMember(utilities_environment_types_options)
				)
				->default_val("development")
				->required();
			_commands[command_name].first
				->add_option(
					"--public-file-path",
					_setup_windows_registry_input_2,
					"File path to the 'qlogicae.public.json' file")
				->default_val(
					configurations_folder_name_string + "\\" + public_file_name_string
				);
			_commands[command_name].first
				->add_option(
					"--private-file-path",
					_setup_windows_registry_input_4,
					"File path to the 'qlogicae.private.json' file")
				->default_val(
					private_file_name_string
				);
			_commands[command_name].first
				->add_option("--is-verbose-logging-enabled",
					_setup_windows_registry_input_5,
					"Enables or disables verbose console logging")
				->default_val(true);

			return true;
		}
		catch (const std::exception& exception)
		{
			_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_setup_windows_registry_command(): ") + exception.what(), _setup_windows_registry_input_5);

			return false;
		}
	}

	bool QLogicaeCLIApplication::_setup_setup_vs2022_application_command()
	{
		try
		{
			std::string command_name = "setup-vs2022-application";
			_commands[command_name] = std::make_pair(
				_application.add_subcommand(
					command_name,
					"Generates a Visual Studio 2022 C++ application template"),
				[this]() -> bool
				{
					try
					{
						_log_running_timestamp_async(_setup_vs2022_application_input_2);

						if (_setup_vs2022_application_input_1.empty())
						{
							return false;
						}

						size_t success_count = 0, total_count = 9;
						if (!std::filesystem::exists(
							_setup_vs2022_application_input_1 +
							assets_folder_path
						))
						{
							std::filesystem::create_directory(
								_setup_vs2022_application_input_1 +
								assets_folder_path
							);
							++success_count;

							_log_info_timestamp_async(
								"'" +
								_setup_vs2022_application_input_1 +
								assets_folder_path +
								"' Created"
							);
						}
						else
						{
							_log_warning_timestamp_async(
								"'" +
								_setup_vs2022_application_input_1 +
								assets_folder_path +
								"' Already Exists"
							);
						}

						if (!std::filesystem::exists(
							_setup_vs2022_application_input_1 +
							scripts_folder_path
						))
						{
							std::filesystem::create_directory(
								_setup_vs2022_application_input_1 +
								scripts_folder_path
							);
							++success_count;

							_log_info_timestamp_async(
								"'" +
								_setup_vs2022_application_input_1 +
								scripts_folder_path +
								"' Created"
							);
						}
						else
						{
							_log_warning_timestamp_async(
								"'" +
								_setup_vs2022_application_input_1 +
								scripts_folder_path +
								"' Already Exists"
							);
						}

						if (!std::filesystem::exists(
							_setup_vs2022_application_input_1 +
							configurations_folder_path
						))
						{
							std::filesystem::create_directory(
								_setup_vs2022_application_input_1 +
								configurations_folder_path
							);
							++success_count;

							_log_info_timestamp_async(
								"'" +
								_setup_vs2022_application_input_1 +
								configurations_folder_path +
								"' Created"
							);
						}
						else
						{
							_log_warning_timestamp_async(
								"'" +
								_setup_vs2022_application_input_1 +
								configurations_folder_path +
								"' Already Exists"
							);
						}

						if (!std::filesystem::exists(
							_setup_vs2022_application_input_1 +
							license_file_path
						))
						{
							std::filesystem::copy_file(
								application_directory_name_string +
								templates_folder_path +
								generic_application_path +
								license_file_name_string,
								_setup_vs2022_application_input_1 +
								license_file_path,
								std::filesystem::copy_options::overwrite_existing
							);
							++success_count;

							_log_info_timestamp_async(
								"'" +
								_setup_vs2022_application_input_1 +
								license_file_path +
								"' Created"
							);
						}
						else
						{
							_log_warning_timestamp_async(
								"'" +
								_setup_vs2022_application_input_1 +
								license_file_path +
								"' Already Exists"
							);
						}

						if (!std::filesystem::exists(
							_setup_vs2022_application_input_1 +
							private_file_path
						))
						{
							std::filesystem::copy_file(
								application_directory_name_string +
								templates_folder_path +
								generic_application_path +
								private_file_name_string,
								_setup_vs2022_application_input_1 +
								private_file_path,
								std::filesystem::copy_options::overwrite_existing
							);
							++success_count;

							_log_info_timestamp_async(
								"'" +
								_setup_vs2022_application_input_1 +
								private_file_path +
								"' Created"
							);
						}
						else
						{
							_log_warning_timestamp_async(
								"'" +
								_setup_vs2022_application_input_1 +
								private_file_path +
								"' Already Exists"
							);
						}

						if (!std::filesystem::exists(
							_setup_vs2022_application_input_1 +
							assets_icon_file_path
						))
						{
							std::filesystem::copy_file(
								application_directory_name_string +
								templates_folder_path +
								generic_application_path +
								icon_file_name_string,
								_setup_vs2022_application_input_1 +
								assets_icon_file_path,
								std::filesystem::copy_options::overwrite_existing
							);
							++success_count;

							_log_info_timestamp_async(
								"'" +
								_setup_vs2022_application_input_1 +
								assets_icon_file_path +
								"' Created"
							);
						}
						else
						{
							_log_warning_timestamp_async(
								"'" +
								_setup_vs2022_application_input_1 +
								assets_icon_file_path +
								"' Already Exists"
							);
						}

						if (!std::filesystem::exists(
							_setup_vs2022_application_input_1 +
							scripts_inno_run_file_path
						))
						{
							std::filesystem::copy_file(
								application_directory_name_string +
								templates_folder_path +
								generic_application_path +
								inno_run_file_name_string,
								_setup_vs2022_application_input_1 +
								scripts_inno_run_file_path,
								std::filesystem::copy_options::overwrite_existing
							);
							++success_count;

							_log_info_timestamp_async(
								"'" +
								_setup_vs2022_application_input_1 +
								scripts_inno_run_file_path +
								"' Created"
							);
						}
						else
						{
							_log_warning_timestamp_async(
								"'" +
								_setup_vs2022_application_input_1 +
								scripts_inno_run_file_path +
								"' Already Exists"
							);
						}

						if (!std::filesystem::exists(
							_setup_vs2022_application_input_1 +
							scripts_inno_setup_file_path
						))
						{
							std::filesystem::copy_file(
								application_directory_name_string +
								templates_folder_path +
								generic_application_path +
								inno_setup_file_name_string,
								_setup_vs2022_application_input_1 +
								scripts_inno_setup_file_path,
								std::filesystem::copy_options::overwrite_existing
							);
							++success_count;

							_log_info_timestamp_async(
								"'" +
								_setup_vs2022_application_input_1 +
								scripts_inno_setup_file_path +
								"' Created"
							);
						}
						else
						{
							_log_warning_timestamp_async(
								"'" +
								_setup_vs2022_application_input_1 +
								scripts_inno_setup_file_path +
								"' Already Exists"
							);
						}

						if (!std::filesystem::exists(
							_setup_vs2022_application_input_1 +
							configurations_public_file_path
						))
						{
							std::filesystem::copy_file(
								application_directory_name_string +
								templates_folder_path +
								generic_application_path +
								public_file_name_string,
								_setup_vs2022_application_input_1 +
								configurations_public_file_path,
								std::filesystem::copy_options::overwrite_existing
							);
							client_public_file.set_file_path(
								std::filesystem::path(
									_setup_vs2022_application_input_1 +
									configurations_public_file_path
								).string()
							);
							client_public_file.update_string(
								{ "application", "id" },
								QLogicaeCore::GENERATOR.random_uuid4()
							);
							client_public_file.update_string(
								{ "environment", "selections", "development" },
								QLogicaeCore::GENERATOR.random_uuid4()
							);
							client_public_file.update_string(
								{ "environment", "selections", "debug" },
								QLogicaeCore::GENERATOR.random_uuid4()
							);
							client_public_file.update_string(
								{ "environment", "selections", "test" },
								QLogicaeCore::GENERATOR.random_uuid4()
							);
							client_public_file.update_string(
								{ "environment", "selections", "release" },
								QLogicaeCore::GENERATOR.random_uuid4()
							);
							++success_count;

							_log_info_timestamp_async(
								"'" +
								_setup_vs2022_application_input_1 +
								configurations_public_file_path +
								"' Created"
							);
						}
						else
						{
							_log_warning_timestamp_async(
								"'" +
								_setup_vs2022_application_input_1 +
								configurations_public_file_path +
								"' Already Exists"
							);
						}

						_log_info_timestamp_async(
							"Results: " +
							absl::StrCat(success_count) + " / " +
							absl::StrCat(total_count) + " Test Cases Passed"
						);

						_log_complete_timestamp_async(_setup_vs2022_application_input_2);
					}
					catch (const std::exception& exception)
					{
						_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_setup_vs2022_application_command(): ") + exception.what(), _setup_vs2022_application_input_2);

						return false;
					}

					return true;
				}
			);
			_commands[command_name].first
				->add_option(
					"--input-folder-path",
					_setup_vs2022_application_input_1,
					"Selected input folder path")
				->default_val(".");
			_commands[command_name].first
				->add_option("--is-verbose-logging-enabled",
					_setup_vs2022_application_input_2,
					"Enables or disables verbose console logging")
				->default_val(true);

			return true;
		}
		catch (const std::exception& exception)
		{
			_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_setup_vs2022_application_command(): ") + exception.what(), _setup_vs2022_application_input_2);

			return false;
		}
	}

	bool QLogicaeCLIApplication::_setup_verify_vs2022_application_command()
	{
		try
		{
			std::string command_name = "verify-vs2022-application";
			_commands[command_name] = std::make_pair(
				_application.add_subcommand(
					command_name,
					"Verifies a selected Visual Studio 2022 C++ application file system"),
				[this]() -> bool
				{
					try
					{
						_log_running_timestamp_async(
							_verify_vs2022_application_input_2
						);

						if (_verify_vs2022_application_input_1
							.empty()
							)
						{
							return false;
						}

						std::string output_string = "";
						size_t success_count = 0, total_count;
						std::vector<std::string> file_paths =
						{
							_verify_vs2022_application_input_1 +
								assets_folder_path,
							_verify_vs2022_application_input_1 +
								scripts_folder_path,
							_verify_vs2022_application_input_1 +
								configurations_folder_path,
							_verify_vs2022_application_input_1 +
								license_file_path,
							_verify_vs2022_application_input_1 +
								private_file_path,
							_verify_vs2022_application_input_1 +
								assets_icon_file_path,
							_verify_vs2022_application_input_1 +
								scripts_inno_run_file_path,
							_verify_vs2022_application_input_1 +
								scripts_inno_setup_file_path,
							_verify_vs2022_application_input_1 +
								configurations_public_file_path
						};
						total_count = file_paths.size();

						for (const std::string& file_path : file_paths)
						{
							if (std::filesystem::exists(file_path))
							{
								output_string +=
									_transform_log_success_timestamp(
										file_path +
										"' Exists"
									);
								++success_count;
							}
							else
							{
								output_string +=
									_transform_log_exception_timestamp(
										file_path +
										"' Not Found"
									);
							}
						}
						output_string +=
							_transform_log_info_timestamp(
								"Results: " +
								absl::StrCat(success_count) + " / " +
								absl::StrCat(total_count) + " Test Cases Passed"
							);
						QLogicaeCore::CLI_IO.print_async(output_string);

						_log_complete_timestamp_async(
							_verify_vs2022_application_input_2
						);
					}
					catch (const std::exception& exception)
					{
						_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_verify_vs2022_application_command(): ") + exception.what(), _verify_vs2022_application_input_2);

						return false;
					}

					return true;
				}
			);
			_commands[command_name].first
				->add_option(
					"--input-folder-path",
					_verify_vs2022_application_input_1,
					"Selected input folder path"
				)
				->default_val(".");
			_commands[command_name].first
				->add_option("--is-verbose-logging-enabled",
					_verify_vs2022_application_input_2,
					"Enables or disables verbose console logging"
				)
				->default_val(true);

			return true;
		}
		catch (const std::exception& exception)
		{
			_log_exception_timestamp_async(std::string("Exception at QLogicaeCLIApplication::_setup_verify_vs2022_application_command(): ") + exception.what(), _verify_vs2022_application_input_2);

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
					command_name,
					"Creates an application installer"),
				[this]() -> bool
				{
					try
					{
						_log_running_timestamp_async(_setup_installer_input_3);

						client_public_file.set_file_path(
							_setup_installer_input_1 +
							configurations_public_file_path
						);
						client_private_file.set_file_path(
							_setup_installer_input_1 +
							private_file_path
						);
						client_inno_run_file.set_file_path(
							_setup_installer_input_1 +
							scripts_inno_run_file_path
						);
						client_inno_setup_file.set_file_path(
							_setup_installer_input_1 +
							scripts_inno_setup_file_path
						);
						client_inno_setup_target_file.set_file_path(
							_setup_installer_input_1 +
							scripts_inno_target_file_path
						);

						if (!std::filesystem::exists(
							_setup_installer_input_1 +
							scripts_folder_path
						))
						{
							std::filesystem::create_directory(
								_setup_installer_input_1 +
								scripts_folder_path
							);
						}

						if (std::filesystem::exists(
							_setup_installer_input_1 +
							scripts_inno_target_file_path)
							)
						{
							std::filesystem::remove(
								_setup_installer_input_1 +
								scripts_inno_target_file_path
							);
						}

						std::filesystem::copy_file(
							_setup_installer_input_1 +
							scripts_inno_setup_file_path,
							_setup_installer_input_1 +
							scripts_inno_target_file_path,
							std::filesystem::copy_options::overwrite_existing
						);

						client_public_file.update_string(
							{ "environment", "selected" }, "release"
						);

						std::string input_folder_path =
							std::filesystem::absolute(
								client_private_file.get_string(
									{ "inno_setup", "input_folder_path" }
								)
							).string();

						std::string output_folder_path =
							std::filesystem::absolute(
								client_private_file.get_string(
									{ "inno_setup", "output_folder_path" }
								)
							).string(),
							client_inno_setup_target_file_output = "";

						std::filesystem::copy_file(
							_setup_installer_input_1 +
							configurations_public_file_path,
							input_folder_path +
							configurations_public_file_path,
							std::filesystem::copy_options::overwrite_existing
						);

						std::unordered_map<std::string, std::any> languages =
							client_private_file.get_object(
								{ "languages" }
							);
						client_inno_setup_target_file_output += "\n[Languages]\n";
						for (const auto& [name, properties] : languages)
						{
							std::unordered_map<std::string, std::any> object =
								std::any_cast<std::unordered_map<
								std::string, std::any>>(properties);
							if (std::any_cast<bool>(object["is_enabled"]))
							{
								client_inno_setup_target_file_output +=
									"Name: \"" + name +
									"\"; MessagesFile: \"" +
									std::any_cast<std::string>(
										object["message_file"]
									) + "\"\n";
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
							client_public_file
							.get_string(
								{
									"environment",
									"selections",
									"release"
								}
							);

						client_inno_setup_target_file_output +=
							"\n[Registry]\n";						
						client_inno_setup_target_file_output +=
							std::string("Root: HKLM; Subkey: \"SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment\"; ") +
							"ValueType: expandsz; ValueName: \"Path\"; ValueData: \"{olddata};{app}\"; " +
							"Flags: uninsdeletevalue\n";

						for (const auto& [key, value] : hkcu_secrets)
						{
							client_inno_setup_target_file_output += 
								"Root: HKCU; Subkey: \"Software\\" +
								application_id +
								"\\" + release_id +
								"\"; ValueType: string; ValueName: \"" +
								std::any_cast<std::string>(key) +
								"\"; ValueData: \"" +
								std::any_cast<std::string>(value) +
								"\"; Flags: uninsdeletekeyifempty\n";
						}
						client_inno_setup_target_file.append(
							client_inno_setup_target_file_output
						);

						system(
							(execute_inno_run_command +
								scripts_inno_run_file_path + "\""
							).c_str()
						);

						client_public_file.update_string(
							{ "environment", "selected" }, "development"
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
				->add_option("--input-folder-path",
					_setup_installer_input_1,
					"Selected input folder path")
				->default_val(".");
			_commands[command_name].first
				->add_option("--output-folder-path",
					_setup_installer_input_2,
					"Selected output folder path")
				->default_val(".");
			_commands[command_name].first
				->add_option("--is-verbose-logging-enabled",
					_setup_installer_input_3,
					"Enables or disables verbose console logging")
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
				"Complete!", QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
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
				"Complete!", QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
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
				QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
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
