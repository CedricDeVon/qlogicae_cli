#include "pch.hpp"

#include "application.hpp"

namespace QLogicaeCLI
{
	Application::Application() :
		_application(
			UTILITIES.get_application_full_name()
		)
	{

	}

	bool Application::setup(int argc, char** argv)
	{
		try
		{
			if (!_setup_about_command() ||
				!_setup_uuid4_command() ||
				!_setup_string_command() ||
				!_setup_xchacha20poly1305_command() ||
				!_setup_argon2id_command() ||
				!_setup_scripts_command())
			{
				return false;
			}

			/*
			if (
				!_setup_environment_command() ||
				!_setup_windows_registry_command() ||
				!_setup_template_command() ||
				!_setup_deploy_command())
			{
				return false;
			}
			*/

			try
			{
				_application.parse(argc, argv);				   
			}
			catch (const CLI::ParseError& exception)
			{
				_application.exit(exception);

				return false;                     
			}

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::setup(): ") + exception.what());

			return false;
		}
	}

	bool Application::parse()
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

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::parse(): ") + exception.what());

			return false;
		}
	}

	Application& Application::get_instance()
	{
		static Application singleton;

		return singleton;
	}

	bool Application::_setup_about_command()
	{
		try
		{
			CLI::App* about_command =
				_application.add_subcommand(
					"about",
					"Project and application details"
				);

			_commands["about"] = std::make_pair(
				about_command,
				[this]() -> bool
				{
					QLogicaeCore::CLI_IO.print(
						UTILITIES.get_application_about_details()
					);

					return true;
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_about_command(): ") + exception.what());

			return false;
		}
	}

	bool Application::_setup_uuid4_command()
	{
		try
		{
			CLI::App* uuid4_command =
				_application.add_subcommand(
					"uuid4",
					"UUID4 commands: generate"
				);
			CLI::App* uuid4_generate_command =
				uuid4_command->add_subcommand(
					"generate",
					"Random uuid4 generation"
				);
			uuid4_generate_command
				->add_option("--count",
					_generate_uuid4_input_1,
					"The number of generated uuid4s")
				->check(CLI::PositiveNumber)
				->default_val(1);
			uuid4_generate_command
				->add_option("--output-file-path",
					_generate_uuid4_input_2,
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");
			uuid4_generate_command
				->add_option("--is-file-output-enabled",
					_generate_uuid4_input_4,
					"Enables or disables the option '--output-file-path'")
				->default_val(false);
			uuid4_generate_command
				->add_option("--is-verbose-logging-enabled",
					_generate_uuid4_input_3,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["uuid4-generate"] = std::make_pair(
				uuid4_generate_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_generate_uuid4_input_3);

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
							UTILITIES.TEXT_FILE_IO.set_file_path(
								UTILITIES.setup_result_output_file(
									_generate_uuid4_input_2,
									"uuid4\\generate",
									UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							UTILITIES.TEXT_FILE_IO.write_async(output_string);
						}

						UTILITIES.log_complete_timestamp_async(_generate_uuid4_input_3);

						return true;
					}
					catch (const std::exception exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_uuid4_command(): ") + exception.what(), _generate_uuid4_input_3);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_uuid4_command(): ") + exception.what(), _generate_uuid4_input_3);

			return false;
		}
	}

	bool Application::_setup_string_command()
	{
		try
		{
			CLI::App* string_command =
				_application.add_subcommand(
					"string",
					"String commands: generate"
				);
			CLI::App* string_generate_command =
				string_command->add_subcommand(
					"generate",
					"Random string generation"
				);
			string_generate_command
				->add_option("--length",
					_generate_string_input_1,
					"The character length of each individual string output")
				->check(CLI::PositiveNumber)
				->default_val(32);
			string_generate_command
				->add_option("--count",
					_generate_string_input_2,
					"The number of generated string outputs")
				->check(CLI::PositiveNumber)
				->default_val(1);
			string_generate_command
				->add_option("--character-set",
					_generate_string_input_3,
					"A string of characters where each individual character can possibly be found within each string output")
				->default_val("");
			string_generate_command
				->add_option("--output-file-path",
					_generate_string_input_4,
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");
			string_generate_command
				->add_option("--is-file-output-enabled",
					_generate_string_input_6,
					"Enables or disables the option '--output-file-path'")
				->default_val(false);
			string_generate_command
				->add_option("--is-verbose-logging-enabled",
					_generate_string_input_5,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["string-generate"] = std::make_pair(
				string_generate_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_generate_string_input_5);

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
							UTILITIES.TEXT_FILE_IO.set_file_path(
								UTILITIES.setup_result_output_file(
									_generate_string_input_4,
									"string\\generate",
									UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							UTILITIES.TEXT_FILE_IO.write_async(output_string);
						}

						UTILITIES.log_complete_timestamp_async(_generate_string_input_5);

						return true;
					}
					catch (const std::exception exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_string_command(): ") + exception.what(), _generate_string_input_5);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_string_command(): ") + exception.what(), _generate_string_input_5);

			return false;
		}
	}

	bool Application::_setup_xchacha20poly1305_command()
	{
		try
		{
			CLI::App* xchacha20poly1305_command =
				_application.add_subcommand(
					"xchacha20poly1305",
					"XChaCha20Poly1305 commands: encrypt, decrypt"
				);
			CLI::App* xchacha20poly1305_encrypt_command =
				xchacha20poly1305_command->add_subcommand(
					"encrypt",
					"Text encryption"
				);

			xchacha20poly1305_encrypt_command
				->add_option("--text",
					_encrypt_xchacha20poly1305_input_1,
					"The string input to be encrypted")
				->required();
			xchacha20poly1305_encrypt_command
				->add_option("--key",
					_encrypt_xchacha20poly1305_input_2,
					"Encryption key")
				->required();
			xchacha20poly1305_encrypt_command
				->add_option("--nonce",
					_encrypt_xchacha20poly1305_input_3,
					"Encryption nonce. WARNING: Nonces must be 32 characters long")
				->default_val(QLogicaeCore::GENERATOR.random_string(
					32, QLogicaeCore::Constants::ALPHA_NUMERIC_CHARACTERS)
				);
			xchacha20poly1305_encrypt_command
				->add_option("--output-file-path",
					_encrypt_xchacha20poly1305_input_4,
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");
			xchacha20poly1305_encrypt_command
				->add_option("--is-file-output-enabled",
					_encrypt_xchacha20poly1305_input_6,
					"Enables or disables the option '--output-file-path'")
				->default_val(false);
			xchacha20poly1305_encrypt_command
				->add_option("--is-verbose-logging-enabled",
					_encrypt_xchacha20poly1305_input_5,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["xchacha20poly1305-encrypt"] = std::make_pair(
				xchacha20poly1305_encrypt_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_encrypt_xchacha20poly1305_input_5);

						if (!_encrypt_xchacha20poly1305_input_1.length() ||
							!_encrypt_xchacha20poly1305_input_2.length() ||
							!_encrypt_xchacha20poly1305_input_3.length())
						{
							UTILITIES.log_complete_timestamp_async(_encrypt_xchacha20poly1305_input_5);

							return false;
						}

						std::string output_string =
							UTILITIES.CRYPTOGRAPHER_1.transform(
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
							UTILITIES.TEXT_FILE_IO.set_file_path(
								UTILITIES.setup_result_output_file(
									_encrypt_xchacha20poly1305_input_4,
									"xchacha20poly1305\\encrypt",
									UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							UTILITIES.TEXT_FILE_IO.write_async(output_string);
						}

						UTILITIES.log_complete_timestamp_async(_encrypt_xchacha20poly1305_input_5);

						return true;
					}
					catch (const std::exception exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_xchacha20poly1305_command(): ") + exception.what(), _encrypt_xchacha20poly1305_input_5);

						return false;
					}
				}
			);

			CLI::App* xchacha20poly1305_decrypt_command =
				xchacha20poly1305_command->add_subcommand(
					"decrypt",
					"Cipher decryption"
				);

			xchacha20poly1305_decrypt_command
				->add_option("--cipher",
					_decrypt_xchacha20poly1305_input_1,
					"The string cipher to be decrypted")
				->required();
			xchacha20poly1305_decrypt_command
				->add_option("--key",
					_decrypt_xchacha20poly1305_input_2,
					"Encryption key")
				->required();
			xchacha20poly1305_decrypt_command
				->add_option("--nonce",
					_decrypt_xchacha20poly1305_input_3,
					"Encryption nonce. WARNING: Nonces must be 32 characters long")
				->required();
			xchacha20poly1305_decrypt_command
				->add_option("--output-file-path",
					_decrypt_xchacha20poly1305_input_4,
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");
			xchacha20poly1305_decrypt_command
				->add_option("--is-file-output-enabled",
					_decrypt_xchacha20poly1305_input_6,
					"Enables or disables the option '--output-file-path'")
				->default_val(false);
			xchacha20poly1305_decrypt_command
				->add_option("--is-verbose-logging-enabled",
					_decrypt_xchacha20poly1305_input_5,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["xchacha20poly1305-decrypt"] = std::make_pair(
				xchacha20poly1305_decrypt_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_decrypt_xchacha20poly1305_input_5);

						if (!_decrypt_xchacha20poly1305_input_1.length() ||
							!_decrypt_xchacha20poly1305_input_2.length() ||
							!_decrypt_xchacha20poly1305_input_3.length())
						{
							UTILITIES.log_complete_timestamp_async(_decrypt_xchacha20poly1305_input_5);

							return false;
						}

						std::string output_string =
							UTILITIES.CRYPTOGRAPHER_1.reverse(
								_decrypt_xchacha20poly1305_input_1,
								_decrypt_xchacha20poly1305_input_2,
								_decrypt_xchacha20poly1305_input_3
							);

						QLogicaeCore::CLI_IO.print_with_new_line_async(
							output_string
						);

						if (_decrypt_xchacha20poly1305_input_6)
						{
							UTILITIES.TEXT_FILE_IO.set_file_path(
								UTILITIES.setup_result_output_file(
									_decrypt_xchacha20poly1305_input_4,
									"xchacha20poly1305\\decrypt",
									UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							UTILITIES.TEXT_FILE_IO.write_async(output_string);
						}

						UTILITIES.log_complete_timestamp_async(_decrypt_xchacha20poly1305_input_5);

						return true;
					}
					catch (const std::exception exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_xchacha20poly1305_command(): ") + exception.what(), _decrypt_xchacha20poly1305_input_5);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_xchacha20poly1305_command(): ") + exception.what(), _encrypt_xchacha20poly1305_input_5);

			return false;
		}
	}

	bool Application::_setup_argon2id_command()
	{
		try
		{
			CLI::App* argon2id_command =
				_application.add_subcommand(
					"argon2id",
					"Argon2ID commands: hash, verify"
				);
			CLI::App* argon2id_encrypt_command =
				argon2id_command->add_subcommand(
					"hash",
					"Text hashing"
				);

			argon2id_encrypt_command
				->add_option("--text",
					_hash_argon2id_input_1,
					"The string text to be hashed")
				->required();
			argon2id_encrypt_command
				->add_option("--output-file-path",
					_hash_argon2id_input_2,
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");
			argon2id_encrypt_command
				->add_option("--is-file-output-enabled",
					_hash_argon2id_input_4,
					"Enables or disables the option '--output-file-path'")
				->default_val(false);
			argon2id_encrypt_command
				->add_option("--is-verbose-logging-enabled",
					_hash_argon2id_input_3,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["argon2id-hash"] = std::make_pair(
				argon2id_encrypt_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_hash_argon2id_input_3);

						if (!_hash_argon2id_input_1.length())
						{
							UTILITIES.log_complete_timestamp_async(_hash_argon2id_input_3);

							return false;
						}

						std::string output_string =
							UTILITIES.CRYPTOGRAPHER_3.transform(
								_hash_argon2id_input_1
							);

						QLogicaeCore::CLI_IO.print_with_new_line_async(
							output_string
						);

						if (_hash_argon2id_input_4)
						{
							UTILITIES.TEXT_FILE_IO.set_file_path(
								UTILITIES.setup_result_output_file(
									_hash_argon2id_input_2,
									"argon2id\\hash",
									UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							UTILITIES.TEXT_FILE_IO.write_async(output_string);
						}

						UTILITIES.log_complete_timestamp_async(_hash_argon2id_input_3);

						return true;
					}
					catch (const std::exception exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_argon2id_command(): ") + exception.what(), _hash_argon2id_input_3);

						return false;
					}
				}
			);

			CLI::App* argon2id_verify_command =
				argon2id_command->add_subcommand(
					"verify",
					"Hash verification"
				);

			argon2id_verify_command
				->add_option("--hash",
					_verify_argon2id_input_1,
					"The string hash to be verified")
				->required();
			argon2id_verify_command
				->add_option("--key",
					_verify_argon2id_input_2,
					"The original text to be compared with the hash")
				->required();
			argon2id_verify_command
				->add_option("--output-file-path",
					_verify_argon2id_input_3,
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");
			argon2id_verify_command
				->add_option("--is-file-output-enabled",
					_verify_argon2id_input_5,
					"Enables or disables the option '--output-file-path'")
				->default_val(false);
			argon2id_verify_command
				->add_option("--is-verbose-logging-enabled",
					_verify_argon2id_input_4,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["argon2id-verify"] = std::make_pair(
				argon2id_verify_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_verify_argon2id_input_4);

						if (!_verify_argon2id_input_1.length() ||
							!_verify_argon2id_input_2.length())
						{
							UTILITIES.log_complete_timestamp_async(_verify_argon2id_input_4);

							return false;
						}

						std::string output_string =
							(UTILITIES.CRYPTOGRAPHER_3.reverse(
								_verify_argon2id_input_1,
								_verify_argon2id_input_2
							)) ? "true" : "false";

						QLogicaeCore::CLI_IO.print_with_new_line_async(
							output_string
						);

						if (_verify_argon2id_input_5)
						{
							UTILITIES.TEXT_FILE_IO.set_file_path(
								UTILITIES.setup_result_output_file(
									_verify_argon2id_input_3,
									"argon2id\\verify",
									UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							UTILITIES.TEXT_FILE_IO.write_async(output_string);
						}

						UTILITIES.log_complete_timestamp_async(_verify_argon2id_input_4);

						return true;
					}
					catch (const std::exception exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_verify_argon2id_command(): ") + exception.what(), _verify_argon2id_input_4);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_argon2id_command(): ") + exception.what(), _hash_argon2id_input_3);

			return false;
		}
	}

	bool Application::_setup_scripts_command()
	{
		try
		{
			CLI::App* scripts_command =
				_application.add_subcommand(
					"scripts",
					"Scripting commands: run"
				);
			CLI::App* scripts_run_command =
				scripts_command->add_subcommand(
					"run",
					"Running scripts"
				);

			scripts_run_command
				->add_option("--names",
					_run_scripts_input_1,
					"Selected script commands")
				->delimiter(',')
				->required();
			scripts_run_command
				->add_option("--is-verbose-logging-enabled",
					_run_scripts_input_3,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["scripts-run"] = std::make_pair(
				scripts_run_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_run_scripts_input_3);

						UTILITIES.CLIENT_DOT_QLOGICAE_FILE.set_file_path(
							UTILITIES.RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_CONFIGURATIONS_QLOGICAE_FILE_PATH
						);
						std::unordered_map<std::string, std::any> scripts =
							UTILITIES.CLIENT_DOT_QLOGICAE_FILE.get_object({ "scripts" }
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
								UTILITIES.log_warning_timestamp_async(
									"Script '" + script_command +
									"' does not exist",
									_run_scripts_input_3
								);
							}
						}

						UTILITIES.log_complete_timestamp_async(_run_scripts_input_3);

						return true;
					}
					catch (const std::exception& exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_scripts_command(): ") + exception.what(), _run_scripts_input_3);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_scripts_command(): ") + exception.what(), _run_scripts_input_3);

			return false;
		}
	}


	/*




	

	bool Application::_setup_environment_command()
	{
		try
		{
			CLI::App* environment_command =
				_application.add_subcommand(
					"environment",
					"Environment commands: set"
				);

			CLI::App* environment_get_command =
				environment_command->add_subcommand(
					"get",
					"Returns the current environment type"
				);

			environment_get_command
				->add_option("--is-verbose-logging-enabled",
					_get_environment_input_2,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["environment-get"] = std::make_pair(
				environment_get_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_get_environment_input_2);

						client_public_file.set_file_path(
							public_qlogicae_configurations_public_file_path
						);
						std::string output_result = client_public_file.get_string(
							{ "environment", "selected" }
						);
						QLogicaeCore::CLI_IO.print_async(output_result);

						UTILITIES.log_complete_timestamp_async(_get_environment_input_2);

						return true;
					}
					catch (const std::exception& exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_environment_command(): ") + exception.what(), _get_environment_input_2);

						return false;
					}
				}
			);

			CLI::App* environment_set_command =
				environment_command->add_subcommand(
					"set",
					"Updates the current environment type"
				);

			environment_set_command
				->add_option("--type",
					_set_environment_input_1,
					"Selected environment type")
				->check(CLI::IsMember(application_environment_types))
				->default_val("development");
			environment_set_command
				->add_option("--is-verbose-logging-enabled",
					_set_environment_input_3,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["environment-set"] = std::make_pair(
				environment_set_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_set_environment_input_3);

						if (_set_environment_input_1.empty())
						{
							return false;
						}

						client_public_file.set_file_path(
							public_qlogicae_configurations_public_file_path
						);
						client_public_file.update_string(
							{ "environment", "selected" },
							_set_environment_input_1
						);

						UTILITIES.log_complete_timestamp_async(_set_environment_input_3);

						return true;
					}
					catch (const std::exception& exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_environment_command(): ") + exception.what(), _set_environment_input_3);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_environment_command(): ") + exception.what(), _set_environment_input_3);

			return false;
		}

	}

	bool Application::_setup_windows_registry_command()
	{
		try
		{
			CLI::App* windows_registry_command =
				_application.add_subcommand(
					"windows-registry",
					"Windows Registry commands: hkcu"
				);
			CLI::App* windows_registry_hkcu_command =
				windows_registry_command->add_subcommand(
					"hkcu",
					"HKCU-specific windows registry"
				);
			CLI::App* windows_registry_hkcu_get_command =
				windows_registry_hkcu_command->add_subcommand(
					"get",
					"Reading key-value pairs of a selected Windows Registry path"
				);

			windows_registry_hkcu_get_command
				->add_option("--sub-path",
					_view_windows_registry_input_1,
					"HKCU Windows Registry path")
				->default_val("")
				->required();
			windows_registry_hkcu_get_command
				->add_option("--is-verbose-logging-enabled",
					_view_windows_registry_input_2,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["windows-registry-hkcu-get"] = std::make_pair(
				windows_registry_hkcu_get_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_view_windows_registry_input_2);

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

						UTILITIES.log_complete_timestamp_async(_view_windows_registry_input_2);

						return true;
					}
					catch (const std::exception& exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_windows_registry_command(): ") + exception.what(), _view_windows_registry_input_2);

						return false;
					}
				}
			);

			CLI::App* windows_registry_hkcu_set_command =
				windows_registry_hkcu_command->add_subcommand(
					"set",
					"Creates or updates a key-value pair of a selected Windows Registry path"
				);

			windows_registry_hkcu_set_command
				->add_option("--sub-path",
					_set_windows_registry_input_1,
					"HKCU Windows Registry path")
				->default_val("")
				->required();
			windows_registry_hkcu_set_command
				->add_option("--key",
					_set_windows_registry_input_2,
					"HKCU Windows Registry key")
				->default_val("")
				->required();
			windows_registry_hkcu_set_command
				->add_option("--value",
					_set_windows_registry_input_3,
					"HKCU Windows Registry value")
				->default_val("")
				->required();
			windows_registry_hkcu_set_command
				->add_option("--is-verbose-logging-enabled",
					_set_windows_registry_input_4,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["windows-registry-hkcu-set"] = std::make_pair(
				windows_registry_hkcu_set_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_set_windows_registry_input_4);

						bool result = QLogicaeCore::WINDOWS_REGISTRY_HKCU.set_value_via_utf8(
							_set_windows_registry_input_1,
							_set_windows_registry_input_2,
							_set_windows_registry_input_3
						);

						UTILITIES.log_complete_timestamp_async(_set_windows_registry_input_4);

						return true;
					}
					catch (const std::exception& exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_setup_windows_registry_command(): ") + exception.what(), _set_windows_registry_input_4);

						return false;
					}
				}
			);

			CLI::App* windows_registry_hkcu_setup_command =
				windows_registry_hkcu_command->add_subcommand(
					"setup",
					"Creates or updates the key-value pairs of a selected QLogicae environment preset"
				);

			windows_registry_hkcu_setup_command
				->add_option(
					"--environment-type",
					_setup_windows_registry_input_1,
					"HKCU Selected environment type")
				->check(CLI::IsMember(application_environment_type_options))
				->default_val("development")
				->required();
			windows_registry_hkcu_setup_command
				->add_option("--is-verbose-logging-enabled",
					_setup_windows_registry_input_5,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["windows-registry-hkcu-setup"] = std::make_pair(
				windows_registry_hkcu_setup_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_setup_windows_registry_input_5);

						client_public_file.set_file_path(
							public_qlogicae_configurations_public_file_path
						);
						client_private_file.set_file_path(
							qlogicae_private_file_path
						);

						std::string client_id =
							client_public_file.get_string(
								{ "application", "id" }
							);
						if (_setup_windows_registry_input_1 == "all")
						{
							for (const std::string& environment_type : application_environment_types)
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
												absl::StrCat("Software\\QLogicae\\Application\\",
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
											absl::StrCat("Software\\QLogicae\\Application\\",
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

						UTILITIES.log_complete_timestamp_async(_setup_windows_registry_input_5);

						return true;
					}
					catch (const std::exception& exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_setup_windows_registry_command(): ") + exception.what(), _setup_windows_registry_input_5);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_windows_registry_command(): ") + exception.what(), _view_windows_registry_input_2);

			return false;
		}
	}

	bool Application::_setup_deploy_command()
	{
		try
		{
			CLI::App* deploy_command =
				_application.add_subcommand(
					"deploy",
					"Deploy commands: inno_setup"
				);
			CLI::App* deploy_inno_setup_command =
				deploy_command->add_subcommand(
					"inno-setup",
					"Creates an application installation executable via Inno Setup"
				);

			deploy_inno_setup_command
				->add_option("--input-folder-path",
					_setup_installer_input_1,
					"Selected input folder path")
				->default_val(".\\");
			deploy_inno_setup_command
				->add_option("--output-folder-path",
					_setup_installer_input_2,
					"Selected output folder path")
				->default_val(".\\");
			deploy_inno_setup_command
				->add_option("--is-verbose-logging-enabled",
					_setup_installer_input_3,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["deploy-inno-setup"] = std::make_pair(
				deploy_inno_setup_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_setup_installer_input_3);

						std::string path_2 =
							_setup_installer_input_1 +
							qlogicae_private_file_path;
						std::string path_3 =
							_setup_installer_input_1 +
							public_qlogicae_scripts_inno_run_file_path;
						std::string path_4 =
							_setup_installer_input_1 +
							public_qlogicae_scripts_inno_setup_file_path;
						std::string path_5 =
							_setup_installer_input_1 +
							public_qlogicae_scripts_inno_target_file_path;
						std::string path_6 =
							_setup_installer_input_1 +
							public_qlogicae_scripts_folder_path;
						std::string path_7;

						client_private_file.set_file_path(path_2);
						client_inno_run_file.set_file_path(path_3);
						client_inno_setup_file.set_file_path(path_4);
						client_inno_setup_target_file.set_file_path(path_5);

						_remove_file_or_folder_if_found(path_5);
						_copy_file_or_folder(path_4, path_5);

						std::string client_input_folder_path =
							std::filesystem::absolute(
								client_private_file.get_string(
									{ "inno_setup", "input_folder_path" }
								)
							).string();

						client_public_file.set_file_path(
							client_input_folder_path +
							"\\" + public_qlogicae_configurations_public_file_path
						);
						client_public_file.update_string(
							{ "environment", "selected" }, "release"
						);
						client_public_file.set_file_path(
							_setup_installer_input_1 +
							"\\" + public_qlogicae_configurations_public_file_path
						);

						std::string client_inno_setup_target_file_output = "";
						std::unordered_map<std::string, std::any> client_languages =
							client_private_file.get_object(
								{ "languages" }
							);
						client_inno_setup_target_file_output += "\n[Languages]\n";
						for (const auto& [name, properties] : client_languages)
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
							client_hkcu_secrets =
							client_private_file.get_object(
								{
									"windows_registry",
									"release",
									"hkcu"
								}
							);
						std::string client_application_id =
							client_public_file
							.get_string(
								{
									"application",
									"id"
								}
							);
						std::string client_release_id =
							client_public_file
							.get_string(
								{
									"environment",
									"selections",
									"release"
								}
							);

						client_inno_setup_target_file_output +=
							hklm_registry_path_setup_command;

						for (const auto& [key, value] : client_hkcu_secrets)
						{
							client_inno_setup_target_file_output +=
								"Root: HKCU; Subkey: \"Software\\QLogicae\\" +
								client_application_id +
								"\\" + client_release_id +
								"\"; ValueType: string; ValueName: \"" +
								std::any_cast<std::string>(key) +
								"\"; ValueData: \"" +
								std::any_cast<std::string>(value) +
								"\"; Flags: uninsdeletekeyifempty\n";
						}
						client_inno_setup_target_file.append(
							client_inno_setup_target_file_output
						);

						system(inno_setup_command.c_str());

						_remove_file_or_folder_if_found(path_5);

						client_public_file.update_string(
							{ "environment", "selected" }, "development"
						);

						UTILITIES.log_complete_timestamp_async(_setup_installer_input_3);

						return true;
					}
					catch (const std::exception& exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_deploy_command(): ") + exception.what(), _setup_installer_input_3);

						return false;
					}
				}
				);

				return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_deploy_command(): ") + exception.what(), _setup_installer_input_3);

			return false;
		}
	}

	bool Application::_setup_template_command()
	{
		try
		{
			CLI::App* setup_command =
				_application.add_subcommand(
					"setup",
					"Setup commands: vs2022 application"
				);
			CLI::App* setup_vs2022_command =
				setup_command->add_subcommand(
					"vs2022",
					"Visual Studio 2022 specific templates"
				);
			CLI::App* setup_vs2022_application_command =
				setup_vs2022_command->add_subcommand(
					"application",
					"Creates an application template developed under Visual Studio 2022"
				);

			setup_vs2022_application_command
				->add_option(
					"--output-folder-path",
					_setup_vs2022_application_input_1,
					"Selected output folder path")
				->default_val(".");
			setup_vs2022_application_command
				->add_option("--is-verbose-logging-enabled",
					_setup_vs2022_application_input_2,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["setup-vs2022-application"] = std::make_pair(
				setup_vs2022_application_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_setup_vs2022_application_input_2);

						std::string output_path =
							application_directory_name_string + "\\" +
							public_qlogicae_folder_path + "\\" +
							qlogicae_cli_folder_path + "\\" +
							templates_folder_name_string + "\\" +
							vs2022_folder_name_string + "\\" +
							application_folder_name_string;

						system(("xcopy \"" + output_path + "\" \"" + _setup_vs2022_application_input_1 + "\" /E /Y /I").c_str());

						client_public_file.set_file_path(
							_setup_vs2022_application_input_1 + "\\" +
							public_qlogicae_configurations_public_file_path
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

						UTILITIES.log_complete_timestamp_async(_setup_vs2022_application_input_2);

						return true;
					}
					catch (const std::exception& exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_template_command(): ") + exception.what(), _setup_vs2022_application_input_2);

						return false;
					}
				}
				);

				return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_template_command(): ") + exception.what(), _setup_vs2022_application_input_2);

			return false;
		}
	}

	*/
}
