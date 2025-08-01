#pragma once

#include "pch.hpp"

#include "application.hpp"

namespace QLogicaeCLI
{
	QLogicaeCLIApplication::QLogicaeCLIApplication() :
		_application(
			QLogicaeCLI::application_full_name
		)
	{
	}

	void QLogicaeCLIApplication::_log_running_timestamp()
	{
		QLogicaeCLI::timestamp_logger.log(
			"Running...", QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
		);
	}

	void QLogicaeCLIApplication::_log_complete_timestamp()
	{
		QLogicaeCLI::timestamp_logger.log(
			"Complete!", QLogicaeCore::LogLevel::SUCCESS
		);
	}

	void QLogicaeCLIApplication::_log_exception_timestamp(
		const std::string_view text
	)
	{
		QLogicaeCLI::timestamp_logger.log(
			text, QLogicaeCore::LogLevel::EXCEPTION
		);
	}

	bool QLogicaeCLIApplication::setup(int argc, char** argv)
	{
		try
		{
			std::string current_command_name;

			current_command_name = "about";
			_commands[current_command_name] = std::make_pair(
				_application.add_subcommand(
					current_command_name, constants.EMPTY_STRING),
				[this]() -> bool
				{
					raw_logger.print(application_full_name);

					return true;
				}
			);





			current_command_name = "generate-uuid4";
			_commands[current_command_name] = std::make_pair(
				_application.add_subcommand(
					current_command_name, constants.EMPTY_STRING),
				[this]() -> bool
				{
					try
					{
						if (!_generate_uuid4_input_1)
						{
							return false;
						}

						_log_running_timestamp();

						for (_index_1 = 0;
							_index_1 < _generate_uuid4_input_1;
							++_index_1)
						{
							raw_logger.print_with_new_line(
								generator.random_uuid4()
							);
						}

						_log_complete_timestamp();
					}
					catch (const std::exception error)
					{
						_log_exception_timestamp(error.what());

						return false;
					}

					return true;
				}
			);
			_commands[current_command_name].first
				->add_option("--count",
					_generate_uuid4_input_1,
					constants.EMPTY_STRING)
				->check(CLI::NonNegativeNumber)
				->default_val(1);





			current_command_name = "generate-string";
			_commands[current_command_name] = std::make_pair(
				_application.add_subcommand(
					current_command_name, constants.EMPTY_STRING),
				[this]() -> bool
				{
					try
					{
						if (!_generate_string_input_1 ||
							!_generate_string_input_2)
						{
							return false;
						}

						_log_running_timestamp();

						for (_index_1 = 0;
							_index_1 < _generate_string_input_2;
							++_index_1)
						{
							raw_logger.print_with_new_line(
								generator.random_string(
									_generate_string_input_1
								)
							);
						}

						_log_complete_timestamp();
					}
					catch (const std::exception error)
					{
						_log_exception_timestamp(error.what());

						return false;
					}

					return true;
				}
			);
			_commands[current_command_name].first
				->add_option("--length",
					_generate_string_input_1,
					constants.EMPTY_STRING)
				->check(CLI::NonNegativeNumber)
				->default_val(32);
			_commands[current_command_name].first
				->add_option("--count",
					_generate_string_input_2,
					constants.EMPTY_STRING)
				->check(CLI::NonNegativeNumber)
				->default_val(1);


			current_command_name = "encrypt-xchacha20poly1305";
			_commands[current_command_name] = std::make_pair(
				_application.add_subcommand(
					current_command_name, constants.EMPTY_STRING),
				[this]() -> bool
				{
					try
					{
						if (_encrypt_xchacha20poly1305_input_3.empty())
						{
							_encrypt_xchacha20poly1305_input_3 =
								generator.random_string(24);
						}

						_log_running_timestamp();

						raw_logger.print_with_new_line(
							cryptographer_1.transform(
								_encrypt_xchacha20poly1305_input_1,
								_encrypt_xchacha20poly1305_input_2,
								_encrypt_xchacha20poly1305_input_3
							) + "\n" +
							_encrypt_xchacha20poly1305_input_3
						);

						_log_complete_timestamp();
					}
					catch (const std::exception error)
					{
						_log_exception_timestamp(error.what());

						return false;
					}

					return true;
				}
			);
			_commands[current_command_name].first
				->add_option("--text",
					_encrypt_xchacha20poly1305_input_1,
					constants.EMPTY_STRING)
				->required();
			_commands[current_command_name].first
				->add_option("--key",
					_encrypt_xchacha20poly1305_input_2,
					constants.EMPTY_STRING)
				->required();
			_commands[current_command_name].first
				->add_option("--nonce",
					_encrypt_xchacha20poly1305_input_3,
					constants.EMPTY_STRING)
				->default_val(QLogicaeCLI::generator.random_string(24));



			current_command_name = "decrypt-xchacha20poly1305";
			_commands[current_command_name] = std::make_pair(
				_application.add_subcommand(
					current_command_name, constants.EMPTY_STRING),
				[this]() -> bool
				{
					try
					{
						_log_running_timestamp();

						raw_logger.print_with_new_line(
							cryptographer_1.reverse(
								_decrypt_xchacha20poly1305_input_1,
								_decrypt_xchacha20poly1305_input_2,
								_decrypt_xchacha20poly1305_input_3
							)
						);

						_log_complete_timestamp();
					}
					catch (const std::exception error)
					{
						_log_exception_timestamp(error.what());

						return false;
					}

					return true;
				}
			);
			_commands[current_command_name].first
				->add_option("--text",
					_decrypt_xchacha20poly1305_input_1,
					constants.EMPTY_STRING)
				->required();
			_commands[current_command_name].first
				->add_option("--key",
					_decrypt_xchacha20poly1305_input_2,
					constants.EMPTY_STRING)
				->required();
			_commands[current_command_name].first
				->add_option("--nonce",
					_decrypt_xchacha20poly1305_input_3,
					constants.EMPTY_STRING)
				->required();





			current_command_name = "hash-argon2id";
			_commands[current_command_name] = std::make_pair(
				_application.add_subcommand(
					current_command_name, constants.EMPTY_STRING),
				[this]() -> bool
				{
					try
					{
						_log_running_timestamp();

						raw_logger.print_with_new_line(
							cryptographer_3.transform(
								_hash_argon2id_input_1
							)
						);

						_log_complete_timestamp();
					}
					catch (const std::exception error)
					{
						_log_exception_timestamp(error.what());

						return false;
					}

					return true;
				}
			);
			_commands[current_command_name].first
				->add_option("--text",
					_hash_argon2id_input_1,
					constants.EMPTY_STRING)
				->required();


			current_command_name = "verify-argon2id";
			_commands[current_command_name] = std::make_pair(
				_application.add_subcommand(
					current_command_name, constants.EMPTY_STRING),
				[this]() -> bool
				{
					try
					{
						_log_running_timestamp();

						raw_logger.print_with_new_line(
							(cryptographer_3.reverse(
								_verify_argon2id_input_1,
								_verify_argon2id_input_2
							)) ? "true" : "false"
						);

						_log_complete_timestamp();
					}
					catch (const std::exception error)
					{
						_log_exception_timestamp(error.what());

						return false;
					}

					return true;
				}
			);
			_commands[current_command_name].first
				->add_option("--hash",
					_verify_argon2id_input_1,
					constants.EMPTY_STRING)
				->required();
			_commands[current_command_name].first
				->add_option("--key",
					_verify_argon2id_input_2,
					constants.EMPTY_STRING)
				->required();



			current_command_name = "set-environment";
			_commands[current_command_name] = std::make_pair(
				_application.add_subcommand(
					current_command_name, constants.EMPTY_STRING),
				[this]() -> bool
				{
					try
					{
						if (_set_environment_input_1.empty() ||
							_set_environment_input_2.empty())
						{
							return false;
						}

						_log_running_timestamp();

						if (!std::filesystem::exists(
							_set_environment_input_2
						))
						{
							timestamp_logger.log(
								"File path '" + _set_environment_input_2 +
								"' does not exist",
								QLogicaeCore::LogLevel::EXCEPTION
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

						_log_complete_timestamp();
					}
					catch (const std::exception error)
					{
						_log_exception_timestamp(error.what());

						return false;
					}

					return true;
				}
			);
			_commands[current_command_name].first
				->add_option("--type",
					_set_environment_input_1,
					constants.EMPTY_STRING)
				->check(CLI::IsMember(utilities_environment_types))
				->default_val("development");
			_commands[current_command_name].first
				->add_option("--utilities-file-path",
					_set_environment_input_2,
					constants.EMPTY_STRING)
				->default_val(
					std::filesystem::path(
						configurations_folder_name / utilities_file_name
					).string()
				);



			current_command_name = "run-scripts";
			_commands[current_command_name] = std::make_pair(
				_application.add_subcommand(
					current_command_name, constants.EMPTY_STRING),
				[this]() -> bool
				{
					try
					{
						if (_run_scripts_input_1.empty() ||
							_run_scripts_input_2.empty())
						{
							return false;
						}

						_log_running_timestamp();

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
								timestamp_logger.log(
									"Script '" + script_command +
									"' does not exist",
									QLogicaeCore::LogLevel::WARNING
								);
							}
						}

						_log_complete_timestamp();
					}
					catch (const std::exception error)
					{
						_log_exception_timestamp(error.what());

						return false;
					}

					return true;
				}
			);
			_commands[current_command_name].first
				->add_option("--names",
					_run_scripts_input_1,
					constants.EMPTY_STRING)
				->delimiter(',')
				->required();
			_commands[current_command_name].first
				->add_option("--utilities-file-path",
					_run_scripts_input_2,
					constants.EMPTY_STRING)
				->default_val(
					std::filesystem::path(
						configurations_folder_name /
						utilities_file_name
					).string()
				);





			current_command_name = "view-windows-registry";
			_commands[current_command_name] = std::make_pair(
				_application.add_subcommand(
					current_command_name, constants.EMPTY_STRING),
				[this]() -> bool
				{
					try
					{
						if (_view_windows_registry_input_1.empty())
						{
							return false;
						}

						_log_running_timestamp();

						std::unordered_map<std::string, std::string> items =
							hkcu_windows_registry.get_values_via_utf8(
								_view_windows_registry_input_1
							);
						for (const auto& [key, value] : items)
						{
							raw_logger.print_with_new_line(
								key + "\t -> " + value
							);
						}

						_log_complete_timestamp();
					}
					catch (const std::exception error)
					{
						_log_exception_timestamp(error.what());

						return false;
					}

					return true;
				}
			);
			_commands[current_command_name].first
				->add_option("--sub-path",
					_view_windows_registry_input_1,
					constants.EMPTY_STRING)
				->default_val(constants.EMPTY_STRING)
				->required();





			current_command_name = "setup-windows-registry";
			_commands[current_command_name] = std::make_pair(
				_application.add_subcommand(
					current_command_name,
					constants.EMPTY_STRING),
				[this]() -> bool
				{
					try
					{
						if (_setup_windows_registry_input_1.empty() ||
							_setup_windows_registry_input_2.empty() ||
							_setup_windows_registry_input_3.empty() ||
							_setup_windows_registry_input_4.empty())
						{
							return false;
						}

						_log_running_timestamp();

						if (!std::filesystem::exists(_setup_windows_registry_input_2))
						{
							timestamp_logger.log(
								fmt::format(
									"File path '{}' does not exist",
									_setup_windows_registry_input_2),
								QLogicaeCore::LogLevel::EXCEPTION
							);

							return false;
						}
						if (!std::filesystem::exists(_setup_windows_registry_input_3))
						{
							timestamp_logger.log(
								fmt::format(
									"File path '{}' does not exist",
									_setup_windows_registry_input_3),
								QLogicaeCore::LogLevel::EXCEPTION
							);

							return false;
						}
						if (!std::filesystem::exists(_setup_windows_registry_input_4))
						{
							timestamp_logger.log(
								fmt::format(
									"File path '{}' does not exist",
									_setup_windows_registry_input_4),
								QLogicaeCore::LogLevel::EXCEPTION
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
										hkcu_windows_registry
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
									timestamp_logger.log(
										"hkcu windows registry setup is disabled. instruction skipped",
										QLogicaeCore::LogLevel::WARNING
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
									hkcu_windows_registry
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
								timestamp_logger.log(
									"hkcu windows registry setup is disabled. instruction skipped",
									QLogicaeCore::LogLevel::WARNING
								);
							}
						}

						_log_complete_timestamp();
					}
					catch (const std::exception error)
					{
						_log_exception_timestamp(error.what());

						return false;
					}

					return true;
				}
			);
			_commands[current_command_name].first
				->add_option(
					"--environment-type",
					_setup_windows_registry_input_1, constants.EMPTY_STRING)
				->check(CLI::IsMember(utilities_environment_types_options)
				)
				->default_val("development")
				->required();
			_commands[current_command_name].first
				->add_option(
					"--public-file-path",
					_setup_windows_registry_input_2, constants.EMPTY_STRING)
				->default_val(
					std::filesystem::path(
						configurations_folder_name /
						public_file_name
					).string()
				);
			_commands[current_command_name].first
				->add_option(
					"--utilities-file-path",
					_setup_windows_registry_input_3, constants.EMPTY_STRING)
				->default_val(
					std::filesystem::path(
						configurations_folder_name /
						utilities_file_name
					).string()
				);
			_commands[current_command_name].first
				->add_option(
					"--private-file-path",
					_setup_windows_registry_input_4, constants.EMPTY_STRING)
				->default_val(
					std::filesystem::path(
						private_file_name
					).string()
				);



			current_command_name = "setup-default-template";
			_commands[current_command_name] = std::make_pair(
				_application.add_subcommand(
					current_command_name, constants.EMPTY_STRING),
				[this]() -> bool
				{
					try
					{
						if (_setup_default_template_input_1.empty())
						{
							return false;
						}

						_log_running_timestamp();

						if (!std::filesystem::exists(
							_setup_default_template_input_1 /
							configurations_folder_name
						))
						{
							std::filesystem::create_directory(
								_setup_default_template_input_1 /
								configurations_folder_name
							);
							timestamp_logger.log(
								fmt::format("Folder '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										configurations_folder_name
									).string()
								),
								QLogicaeCore::LogLevel::INFO
							);
						}
						else
						{
							timestamp_logger.log(
								fmt::format("Folder '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										configurations_folder_name
									).string()
								),
								QLogicaeCore::LogLevel::WARNING
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
							timestamp_logger.log(
								fmt::format("Folder '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										assets_folder_name
									).string()
								),
								QLogicaeCore::LogLevel::INFO
							);
						}
						else
						{
							timestamp_logger.log(
								fmt::format("Folder '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										assets_folder_name
									).string()
								),
								QLogicaeCore::LogLevel::WARNING
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
							timestamp_logger.log(
								fmt::format("Folder '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										scripts_folder_name
									).string()
								),
								QLogicaeCore::LogLevel::INFO
							);
						}
						else
						{
							timestamp_logger.log(
								fmt::format("Folder '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										scripts_folder_name
									).string()
								),
								QLogicaeCore::LogLevel::WARNING
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
								generator.random_uuid4()
							);

							timestamp_logger.log(
								fmt::format("File '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										configurations_folder_name /
										public_file_name
									).string()
								),
								QLogicaeCore::LogLevel::INFO
							);
						}
						else
						{
							timestamp_logger.log(
								fmt::format("Folder '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										configurations_folder_name /
										public_file_name
									).string()
								),
								QLogicaeCore::LogLevel::WARNING
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
								generator.random_uuid4()
							);
							client_utilities_file.update_string(
								{ "environment", "selections", "debug" },
								generator.random_uuid4()
							);
							client_utilities_file.update_string(
								{ "environment", "selections", "test" },
								generator.random_uuid4()
							);
							client_utilities_file.update_string(
								{ "environment", "selections", "release" },
								generator.random_uuid4()
							);

							timestamp_logger.log(
								fmt::format("File '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										configurations_folder_name /
										utilities_file_name
									).string()
								),
								QLogicaeCore::LogLevel::INFO
							);
						}
						else
						{
							timestamp_logger.log(
								fmt::format("File '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										configurations_folder_name /
										utilities_file_name
									).string()
								),
								QLogicaeCore::LogLevel::WARNING
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
							timestamp_logger.log(
								fmt::format("File '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										private_file_name
									).string()
								),
								QLogicaeCore::LogLevel::INFO
							);
						}
						else
						{
							timestamp_logger.log(
								fmt::format("File '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										private_file_name
									).string()
								),
								QLogicaeCore::LogLevel::WARNING
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
							timestamp_logger.log(
								fmt::format("File '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										gitignore_file_name
									).string()
								),
								QLogicaeCore::LogLevel::INFO
							);
						}
						else
						{
							timestamp_logger.log(
								fmt::format("File '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										gitignore_file_name
									).string()
								),
								QLogicaeCore::LogLevel::WARNING
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
							timestamp_logger.log(
								fmt::format("File '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										license_file_name
									).string()
								),
								QLogicaeCore::LogLevel::INFO
							);
						}
						else
						{
							timestamp_logger.log(
								fmt::format("File '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										license_file_name
									).string()
								),
								QLogicaeCore::LogLevel::WARNING
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
							timestamp_logger.log(
								fmt::format("File '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										scripts_folder_name /
										inno_run_file_name
									).string()
								),
								QLogicaeCore::LogLevel::INFO
							);
						}
						else
						{
							timestamp_logger.log(
								fmt::format("File '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										scripts_folder_name /
										inno_run_file_name
									).string()
								),
								QLogicaeCore::LogLevel::WARNING
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
							timestamp_logger.log(
								fmt::format("File '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										scripts_folder_name /
										inno_setup_file_name
									).string()
								),
								QLogicaeCore::LogLevel::INFO
							);
						}
						else
						{
							timestamp_logger.log(
								fmt::format("File '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										scripts_folder_name /
										inno_setup_file_name
									).string()
								),
								QLogicaeCore::LogLevel::WARNING
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
							timestamp_logger.log(
								fmt::format("File '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										assets_folder_name /
										icon_file_name
									).string()
								),
								QLogicaeCore::LogLevel::INFO
							);
						}
						else
						{
							timestamp_logger.log(
								fmt::format("File '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										assets_folder_name /
										icon_file_name
									).string()
								),
								QLogicaeCore::LogLevel::WARNING
							);
						}

						_log_complete_timestamp();
					}
					catch (const std::exception error)
					{
						_log_exception_timestamp(error.what());

						return false;
					}

					return true;
				}
			);
			_commands[current_command_name].first
				->add_option("--target-root-project-directory", _setup_default_template_input_1, constants.EMPTY_STRING)
				->default_val(".");



			current_command_name = "verify-default-filesystem";
			_commands[current_command_name] = std::make_pair(
				_application.add_subcommand(
					current_command_name, constants.EMPTY_STRING),
				[this]() -> bool
				{
					try
					{
						if (_verify_default_template_input_1.empty())
						{
							return false;
						}

						_log_running_timestamp();

						std::vector<std::filesystem::path> file_paths =
						{
							std::filesystem::path(
								_verify_default_template_input_1 /
								scripts_folder_name /
								inno_run_file_name
							),
							std::filesystem::path(
								_verify_default_template_input_1 /
								scripts_folder_name /
								inno_setup_file_name
							),
							std::filesystem::path(
								_verify_default_template_input_1 /
								configurations_folder_name /
								utilities_file_name
							),
							std::filesystem::path(
								_verify_default_template_input_1 /
								configurations_folder_name /
								public_file_name
							),
							std::filesystem::path(
								_verify_default_template_input_1 /
								private_file_name
							),
							std::filesystem::path(
								_verify_default_template_input_1 /
								license_file_name
							),
							std::filesystem::path(
								_verify_default_template_input_1 /
								gitignore_file_name
							)
						};

						for (const auto& file_path : file_paths)
						{
							if (std::filesystem::exists(file_path))
							{
								timestamp_logger.log(
									fmt::format(
										"File '{}' exists",
										file_path.string()
									),
									QLogicaeCore::LogLevel::SUCCESS
								);
							}
							else
							{
								timestamp_logger.log(
									fmt::format(
										"File '{}' does not exist",
										file_path.string()
									),
									QLogicaeCore::LogLevel::EXCEPTION
								);
							}
						}

						_log_complete_timestamp();
					}
					catch (const std::exception error)
					{
						_log_exception_timestamp(error.what());

						return false;
					}

					return true;
				}
			);
			_commands[current_command_name].first
				->add_option("--target-root-project-directory", _verify_default_template_input_1, constants.EMPTY_STRING)
				->default_val(".");



			current_command_name = "setup-installer";
			_commands[current_command_name] = std::make_pair(
				_application.add_subcommand(
					current_command_name, constants.EMPTY_STRING),
				[this]() -> bool
				{
					try
					{
						_log_running_timestamp();

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
							generator.random_uuid4()
						);
						client_utilities_file.update_string(
							{ "environment", "selections", "debug" },
							generator.random_uuid4()
						);
						client_utilities_file.update_string(
							{ "environment", "selections", "test" },
							generator.random_uuid4()
						);
						client_utilities_file.update_string(
							{ "environment", "selections", "release" },
							generator.random_uuid4()
						);
						client_public_file.update_string(
							{ "application", "id" },
							generator.random_uuid4()
						);

						_log_complete_timestamp();
					}
					catch (const std::exception error)
					{
						_log_exception_timestamp(error.what());

						return false;
					}

					return true;
				}
			);
			_commands[current_command_name].first
				->add_option("--target-project-folder",
					_setup_installer_input_1,
					constants.EMPTY_STRING)
				->default_val(".");
			_commands[current_command_name].first
				->add_option("--output-directory",
					_setup_installer_input_2,
					constants.EMPTY_STRING)
				->default_val(".");


			CLI11_PARSE(_application, argc, argv);
		}
		catch (...)
		{
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
		catch (...)
		{
			return false;
		}

		return true;
	}

	QLogicaeCLIApplication& QLogicaeCLIApplication::get_instance()
	{
		static QLogicaeCLIApplication singleton;

		return singleton;
	}
}
