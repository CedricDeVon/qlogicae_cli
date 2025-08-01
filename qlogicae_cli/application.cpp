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

	bool QLogicaeCLIApplication::setup(int argc, char** argv)
	{
		try
		{
			_commands["about"] = std::make_pair(
				_application.add_subcommand("about", ""),
				[this]() -> bool
				{
					QLogicaeCLI::raw_logger.print(
						QLogicaeCLI::application_full_name
					);

					return true;
				}
			);



			_commands["generate-uuid4"] = std::make_pair(
				_application.add_subcommand(
					"generate-uuid4", ""),
				[this]() -> bool
				{
					try
					{
						if (!_generate_uuid4_input_1)
						{
							return false;
						}

						QLogicaeCLI::timestamp_logger.log(
							"Running...", QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
						);
						QLogicaeCLI::raw_logger.print_with_new_line();

						for (_index_1 = 0;
							_index_1 < _generate_uuid4_input_1;
							++_index_1)
						{
							QLogicaeCLI::raw_logger.print_with_new_line(
								QLogicaeCore::Generator::get_instance().random_uuid4()
							);
						}

						QLogicaeCLI::raw_logger.print_with_new_line();
						QLogicaeCLI::timestamp_logger.log(
							"Complete!", QLogicaeCore::LogLevel::SUCCESS
						);
					}
					catch (const std::exception error)
					{
						QLogicaeCLI::timestamp_logger.log(
							error.what(), QLogicaeCore::LogLevel::EXCEPTION);

						return false;
					}

					return true;
				}
			);
			_commands["generate-uuid4"].first
				->add_option("--count", _generate_uuid4_input_1, "")
				->check(CLI::NonNegativeNumber)
				->default_val(1);



			_commands["generate-string"] = std::make_pair(
				_application.add_subcommand(
					"generate-string", ""),
				[this]() -> bool
				{
					try
					{
						if (!_generate_string_input_1 ||
							!_generate_string_input_2)
						{
							return false;
						}

						QLogicaeCLI::timestamp_logger.log(
							"Running...",
							QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
						);
						QLogicaeCLI::raw_logger.print_with_new_line();

						for (_index_1 = 0;
							_index_1 < _generate_string_input_2;
							++_index_1)
						{
							QLogicaeCLI::raw_logger.print_with_new_line(
								QLogicaeCore::Generator::get_instance()
								.random_string(_generate_string_input_1)
							);
						}

						QLogicaeCLI::raw_logger.print_with_new_line();
						QLogicaeCLI::timestamp_logger.log(
							"Complete!", QLogicaeCore::LogLevel::SUCCESS
						);
					}
					catch (const std::exception error)
					{
						QLogicaeCLI::timestamp_logger.log(
							error.what(), QLogicaeCore::LogLevel::EXCEPTION
						);

						return false;
					}

					return true;
				}
			);
			_commands["generate-string"].first
				->add_option("--length", _generate_string_input_1, "")
				->check(CLI::NonNegativeNumber)
				->default_val(32);
			_commands["generate-string"].first
				->add_option("--count", _generate_string_input_2, "")
				->check(CLI::NonNegativeNumber)
				->default_val(1);



			_commands["encrypt-xchacha20poly1305"] = std::make_pair(
				_application.add_subcommand(
					"encrypt-xchacha20poly1305", ""),
				[this]() -> bool
				{
					try
					{
						if (_encrypt_xchacha20poly1305_input_3.empty())
						{
							_encrypt_xchacha20poly1305_input_3 =
								QLogicaeCLI::generator.random_string(24);
						}

						QLogicaeCLI::timestamp_logger.log(
							"Running...",
							QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
						);
						QLogicaeCLI::raw_logger.print_with_new_line();

						QLogicaeCLI::raw_logger.print_with_new_line(
							QLogicaeCLI::cryptographer_1.transform(
								_encrypt_xchacha20poly1305_input_1,
								_encrypt_xchacha20poly1305_input_2,
								_encrypt_xchacha20poly1305_input_3
							)
						);
						QLogicaeCLI::raw_logger.print_with_new_line();
						QLogicaeCLI::raw_logger.print_with_new_line(
							_encrypt_xchacha20poly1305_input_3
						);

						QLogicaeCLI::raw_logger.print_with_new_line();
						QLogicaeCLI::timestamp_logger.log(
							"Complete!", QLogicaeCore::LogLevel::SUCCESS
						);
					}
					catch (const std::exception error)
					{
						QLogicaeCLI::timestamp_logger.log(
							error.what(), QLogicaeCore::LogLevel::EXCEPTION);

						return false;
					}

					return true;
				}
			);
			_commands["encrypt-xchacha20poly1305"].first
				->add_option("--text", _encrypt_xchacha20poly1305_input_1, "")
				->required();
			_commands["encrypt-xchacha20poly1305"].first
				->add_option("--key", _encrypt_xchacha20poly1305_input_2, "")
				->required();
			_commands["encrypt-xchacha20poly1305"].first
				->add_option("--nonce", _encrypt_xchacha20poly1305_input_3, "")
				->default_val(QLogicaeCLI::generator.random_string(24));




			_commands["decrypt-xchacha20poly1305"] = std::make_pair(
				_application.add_subcommand(
					"decrypt-xchacha20poly1305", ""),
				[this]() -> bool
				{
					try
					{
						QLogicaeCLI::timestamp_logger.log(
							"Running...", QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
						);
						QLogicaeCLI::raw_logger.print_with_new_line();

						QLogicaeCLI::raw_logger.print_with_new_line(
							QLogicaeCLI::cryptographer_1.reverse(
								_decrypt_xchacha20poly1305_input_1,
								_decrypt_xchacha20poly1305_input_2,
								_decrypt_xchacha20poly1305_input_3
							)
						);

						QLogicaeCLI::raw_logger.print_with_new_line();
						QLogicaeCLI::timestamp_logger.log(
							"Complete!", QLogicaeCore::LogLevel::SUCCESS
						);
					}
					catch (const std::exception error)
					{
						QLogicaeCLI::timestamp_logger.log(
							error.what(), QLogicaeCore::LogLevel::EXCEPTION);

						return false;
					}

					return true;
				}
			);
			_commands["decrypt-xchacha20poly1305"].first
				->add_option("--text", _decrypt_xchacha20poly1305_input_1, "")
				->required();
			_commands["decrypt-xchacha20poly1305"].first
				->add_option("--key", _decrypt_xchacha20poly1305_input_2, "")
				->required();
			_commands["decrypt-xchacha20poly1305"].first
				->add_option("--nonce", _decrypt_xchacha20poly1305_input_3, "")
				->required();



			_commands["hash-argon2id"] = std::make_pair(
				_application.add_subcommand(
					"hash-argon2id", ""),
				[this]() -> bool
				{
					try
					{
						QLogicaeCLI::timestamp_logger.log(
							"Running...", QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
						);
						QLogicaeCLI::raw_logger.print_with_new_line();

						QLogicaeCLI::raw_logger.print_with_new_line(
							QLogicaeCLI::cryptographer_3.transform(
								_hash_argon2id_input_1
							)
						);

						QLogicaeCLI::raw_logger.print_with_new_line();
						QLogicaeCLI::timestamp_logger.log(
							"Complete!", QLogicaeCore::LogLevel::SUCCESS
						);
					}
					catch (const std::exception error)
					{
						QLogicaeCLI::timestamp_logger.log(
							error.what(), QLogicaeCore::LogLevel::EXCEPTION
						);

						return false;
					}

					return true;
				}
			);
			_commands["hash-argon2id"].first
				->add_option("--text", _hash_argon2id_input_1, "")
				->required();



			_commands["verify-argon2id"] = std::make_pair(
				_application.add_subcommand(
					"verify-argon2id", ""),
				[this]() -> bool
				{
					try
					{
						QLogicaeCLI::timestamp_logger.log(
							"Running...", QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
						);
						QLogicaeCLI::raw_logger.print_with_new_line();

						const bool is_successful =
							QLogicaeCLI::cryptographer_3.reverse(
								_verify_argon2id_input_1,
								_verify_argon2id_input_2
							);
						QLogicaeCLI::raw_logger.print_with_new_line(
							(is_successful) ? "true" : "false"
						);

						QLogicaeCLI::raw_logger.print_with_new_line();
						QLogicaeCLI::timestamp_logger.log(
							"Complete!", QLogicaeCore::LogLevel::SUCCESS
						);
					}
					catch (const std::exception error)
					{
						QLogicaeCLI::timestamp_logger.log(
							error.what(), QLogicaeCore::LogLevel::EXCEPTION
						);

						return false;
					}

					return true;
				}
			);
			_commands["verify-argon2id"].first
				->add_option("--hash", _verify_argon2id_input_1, "")
				->required();
			_commands["verify-argon2id"].first
				->add_option("--key", _verify_argon2id_input_2, "")
				->required();



			_commands["set-environment"] = std::make_pair(
				_application.add_subcommand(
					"set-environment", ""),
				[this]() -> bool
				{
					try
					{
						if (_set_environment_input_1.empty() ||
							_set_environment_input_2.empty())
						{
							return false;
						}

						QLogicaeCLI::timestamp_logger.log(
							"Running...", QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
						);

						if (!std::filesystem::exists(
							_set_environment_input_2
						))
						{
							QLogicaeCLI::timestamp_logger.log(
								fmt::format(
									"File path '{}' does not exist",
									_set_environment_input_2),
								QLogicaeCore::LogLevel::EXCEPTION
							);

							return false;
						}

						QLogicaeCLI::client_utilities_file.set_file_path(
							_set_environment_input_2
						);
						QLogicaeCLI::client_utilities_file.update_string(
							{ "environment", "selected" },
							_set_environment_input_1
						);

						QLogicaeCLI::timestamp_logger.log(
							"Complete!", QLogicaeCore::LogLevel::SUCCESS
						);
					}
					catch (const std::exception error)
					{
						QLogicaeCLI::timestamp_logger.log(
							error.what(), QLogicaeCore::LogLevel::EXCEPTION);

						return false;
					}

					return true;
				}
			);

			_commands["set-environment"].first
				->add_option("--type", _set_environment_input_1, "")
				->check(CLI::IsMember(QLogicaeCLI::utilities_environment_types))
				->default_val("development");
			_commands["set-environment"].first
				->add_option("--utilities-file-path", _set_environment_input_2, "")
				->default_val(
					std::filesystem::path(
						QLogicaeCLI::configurations_folder_name /
						QLogicaeCLI::utilities_file_name
					).string()
				);

			_commands["run-scripts"] = std::make_pair(
				_application.add_subcommand(
					"run-scripts", ""),
				[this]() -> bool
				{
					try
					{
						if (_run_scripts_input_2.empty())
						{
							return false;
						}

						QLogicaeCLI::timestamp_logger.log(
							"Running...", QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
						);

						QLogicaeCLI::client_utilities_file.set_file_path(
							_run_scripts_input_2
						);
						std::unordered_map<std::string, std::any> scripts =
							QLogicaeCLI::client_utilities_file
							.get_object({ "scripts" }
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
								QLogicaeCLI::timestamp_logger.log(
									fmt::format(
										"Script '{}' does not exist",
										script_command
									), QLogicaeCore::LogLevel::WARNING
								);
							}
						}

						QLogicaeCLI::timestamp_logger.log(
							"Complete!", QLogicaeCore::LogLevel::SUCCESS
						);
					}
					catch (const std::exception error)
					{
						QLogicaeCLI::timestamp_logger.log(
							error.what(), QLogicaeCore::LogLevel::EXCEPTION);

						return false;
					}

					return true;
				}
			);
			_commands["run-scripts"].first
				->add_option("--names", _run_scripts_input_1, "")
				->delimiter(',')
				->required();
			_commands["run-scripts"].first
				->add_option("--utilities-file-path", _run_scripts_input_2, "")
				->default_val(
					std::filesystem::path(
						QLogicaeCLI::configurations_folder_name /
						QLogicaeCLI::utilities_file_name
					).string()
				);

			

			_commands["setup-windows-registry"] = std::make_pair(
				_application.add_subcommand(
					"setup-windows-registry", ""),
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

						QLogicaeCLI::timestamp_logger.log(
							"Running...", QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
						);

						if (!std::filesystem::exists(_setup_windows_registry_input_2))
						{
							QLogicaeCLI::timestamp_logger.log(
								fmt::format(
									"File path '{}' does not exist",
									_setup_windows_registry_input_2),
								QLogicaeCore::LogLevel::EXCEPTION
							);

							return false;
						}
						if (!std::filesystem::exists(_setup_windows_registry_input_3))
						{
							QLogicaeCLI::timestamp_logger.log(
								fmt::format(
									"File path '{}' does not exist",
									_setup_windows_registry_input_3),
								QLogicaeCore::LogLevel::EXCEPTION
							);

							return false;
						}
						if (!std::filesystem::exists(_setup_windows_registry_input_4))
						{
							QLogicaeCLI::timestamp_logger.log(
								fmt::format(
									"File path '{}' does not exist",
									_setup_windows_registry_input_4),
								QLogicaeCore::LogLevel::EXCEPTION
							);

							return false;
						}

						QLogicaeCLI::client_public_file.set_file_path(
							_setup_windows_registry_input_2
						);
						QLogicaeCLI::client_utilities_file.set_file_path(
							_setup_windows_registry_input_3
						);
						QLogicaeCLI::client_private_file.set_file_path(
							_setup_windows_registry_input_4
						);

						std::string client_id =
							QLogicaeCLI::client_public_file.get_string(
								{ "application", "id" }
							);
						if (_setup_windows_registry_input_1 == "all")
						{
							for (const std::string& environment_type : QLogicaeCLI::utilities_environment_types)
							{
								std::string environment_id =
									QLogicaeCLI::client_utilities_file.get_string(
										{ "environment", "selections",
										environment_type }
									);
								std::unordered_map<std::string, std::any>
									hkcu_secrets =
									QLogicaeCLI::client_private_file.get_object(
										{
											"windows_registry",
											environment_type,
											"hkcu"
										}
									);
								std::unordered_map<std::string, std::any>
									is_root_key_used =
									QLogicaeCLI::client_private_file.get_object(
										{ "windows_registry", "is_root_key_used" }
									);

								if (std::any_cast<bool>(is_root_key_used["hkcu"]))
								{
									for (const auto& [key, value] : hkcu_secrets)
									{
										QLogicaeCore::WindowsRegistry::hkcu()
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
									QLogicaeCLI::timestamp_logger.log(
										"hkcu windows registry setup is disabled. instruction skipped",
										QLogicaeCore::LogLevel::WARNING
									);
								}
							}
						}
						else
						{
							std::string environment_id =
								QLogicaeCLI::client_utilities_file.get_string(
									{ "environment", "selections",
									_setup_windows_registry_input_1 }
								);
							std::unordered_map<std::string, std::any>
								hkcu_secrets =
								QLogicaeCLI::client_private_file.get_object(
									{
										"windows_registry",
										_setup_windows_registry_input_1,
										"hkcu"
									}
								);
							std::unordered_map<std::string, std::any>
								is_root_key_used =
								QLogicaeCLI::client_private_file.get_object(
									{ "windows_registry", "is_root_key_used" }
								);

							if (std::any_cast<bool>(is_root_key_used["hkcu"]))
							{
								for (const auto& [key, value] : hkcu_secrets)
								{
									QLogicaeCore::WindowsRegistry::hkcu()
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
								QLogicaeCLI::timestamp_logger.log(
									"hkcu windows registry setup is disabled. instruction skipped",
									QLogicaeCore::LogLevel::WARNING
								);
							}
						}

						QLogicaeCLI::timestamp_logger.log(
							"Complete!", QLogicaeCore::LogLevel::SUCCESS
						);
					}
					catch (const std::exception error)
					{
						QLogicaeCLI::timestamp_logger.log(
							error.what(), QLogicaeCore::LogLevel::EXCEPTION);

						return false;
					}

					return true;
				}
			);
			_commands["setup-windows-registry"].first
				->add_option(
					"--environment-type",
					_setup_windows_registry_input_1, "")
				->check(CLI::IsMember(QLogicaeCLI::utilities_environment_types_options)
				)
				->default_val("development")
				->required();
			_commands["setup-windows-registry"].first
				->add_option(
					"--public-file-path",
					_setup_windows_registry_input_2, "")
				->default_val(
					std::filesystem::path(
						QLogicaeCLI::configurations_folder_name /
						QLogicaeCLI::public_file_name
					).string()
				);
			_commands["setup-windows-registry"].first
				->add_option(
					"--utilities-file-path",
					_setup_windows_registry_input_3, "")
				->default_val(
					std::filesystem::path(
						QLogicaeCLI::configurations_folder_name /
						QLogicaeCLI::utilities_file_name
					).string()
				);
			_commands["setup-windows-registry"].first
				->add_option(
					"--private-file-path",
					_setup_windows_registry_input_4, "")
				->default_val(
					std::filesystem::path(
						QLogicaeCLI::private_file_name
					).string()
				);
			
			

			_commands["setup-default-template"] = std::make_pair(
				_application.add_subcommand(
					"setup-default-template", ""),
				[this]() -> bool
				{
					try
					{
						if (_setup_default_template_input_1.empty())
						{
							return false;
						}

						QLogicaeCLI::timestamp_logger.log(
							"Running...",
							QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
						);

						if (!std::filesystem::exists(
							_setup_default_template_input_1 /
							QLogicaeCLI::configurations_folder_name
						))
						{
							std::filesystem::create_directory(
								_setup_default_template_input_1 /
								QLogicaeCLI::configurations_folder_name
							);
							QLogicaeCLI::timestamp_logger.log(
								fmt::format("Folder '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										QLogicaeCLI::configurations_folder_name
									).string()
								),
								QLogicaeCore::LogLevel::INFO
							);
						}
						else
						{
							QLogicaeCLI::timestamp_logger.log(
								fmt::format("Folder '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										QLogicaeCLI::configurations_folder_name
									).string()
								),
								QLogicaeCore::LogLevel::WARNING
							);
						}

						if (!std::filesystem::exists(
							_setup_default_template_input_1 /
							QLogicaeCLI::assets_folder_name
						))
						{
							std::filesystem::create_directory(
								_setup_default_template_input_1 /
								QLogicaeCLI::assets_folder_name
							);
							QLogicaeCLI::timestamp_logger.log(
								fmt::format("Folder '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										QLogicaeCLI::assets_folder_name
									).string()
								),
								QLogicaeCore::LogLevel::INFO
							);
						}
						else
						{
							QLogicaeCLI::timestamp_logger.log(
								fmt::format("Folder '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										QLogicaeCLI::assets_folder_name
									).string()
								),
								QLogicaeCore::LogLevel::WARNING
							);
						}

						if (!std::filesystem::exists(
							_setup_default_template_input_1 /
							QLogicaeCLI::scripts_folder_name
						))
						{
							std::filesystem::create_directory(
								_setup_default_template_input_1 /
								QLogicaeCLI::scripts_folder_name
							);
							QLogicaeCLI::timestamp_logger.log(
								fmt::format("Folder '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										QLogicaeCLI::scripts_folder_name
									).string()
								),
								QLogicaeCore::LogLevel::INFO
							);
						}
						else
						{
							QLogicaeCLI::timestamp_logger.log(
								fmt::format("Folder '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										QLogicaeCLI::scripts_folder_name
									).string()
								),
								QLogicaeCore::LogLevel::WARNING
							);
						}

						if (!std::filesystem::exists(
							_setup_default_template_input_1 /
							QLogicaeCLI::configurations_folder_name /
							QLogicaeCLI::public_file_name
						))
						{
							std::filesystem::copy_file(
								QLogicaeCLI::application_directory /
								QLogicaeCLI::templates_folder_name /
								"default" /
								QLogicaeCLI::public_file_name,
								_setup_default_template_input_1 /
								QLogicaeCLI::configurations_folder_name /
								QLogicaeCLI::public_file_name,
								std::filesystem::copy_options::overwrite_existing
							);
							QLogicaeCLI::client_public_file.set_file_path(
								std::filesystem::path(
									_setup_default_template_input_1 /
									QLogicaeCLI::configurations_folder_name /
									QLogicaeCLI::public_file_name
								).string()
							);
							QLogicaeCLI::client_public_file.update_string(
								{ "application", "id" },
								QLogicaeCLI::generator.random_uuid4()
							);

							QLogicaeCLI::timestamp_logger.log(
								fmt::format("File '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										QLogicaeCLI::configurations_folder_name /
										QLogicaeCLI::public_file_name
									).string()
								),
								QLogicaeCore::LogLevel::INFO
							);
						}
						else
						{
							QLogicaeCLI::timestamp_logger.log(
								fmt::format("Folder '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										QLogicaeCLI::configurations_folder_name /
										QLogicaeCLI::public_file_name
									).string()
								),
								QLogicaeCore::LogLevel::WARNING
							);
						}

						if (!std::filesystem::exists(
							_setup_default_template_input_1 /
							QLogicaeCLI::configurations_folder_name /
							QLogicaeCLI::utilities_file_name
						))
						{
							std::filesystem::copy_file(
								QLogicaeCLI::application_directory /
								QLogicaeCLI::templates_folder_name /
								"default" /
								QLogicaeCLI::utilities_file_name,
								_setup_default_template_input_1 /
								QLogicaeCLI::configurations_folder_name /
								QLogicaeCLI::utilities_file_name,
								std::filesystem::copy_options::overwrite_existing
							);
							QLogicaeCLI::client_utilities_file.set_file_path(
								std::filesystem::path(
									_setup_default_template_input_1 /
									QLogicaeCLI::configurations_folder_name /
									QLogicaeCLI::utilities_file_name
								).string()
							);
							QLogicaeCLI::client_utilities_file.update_string(
								{ "environment", "selections", "development" },
								QLogicaeCLI::generator.random_uuid4()
							);
							QLogicaeCLI::client_utilities_file.update_string(
								{ "environment", "selections", "debug" },
								QLogicaeCLI::generator.random_uuid4()
							);
							QLogicaeCLI::client_utilities_file.update_string(
								{ "environment", "selections", "test" },
								QLogicaeCLI::generator.random_uuid4()
							);
							QLogicaeCLI::client_utilities_file.update_string(
								{ "environment", "selections", "release" },
								QLogicaeCLI::generator.random_uuid4()
							);

							QLogicaeCLI::timestamp_logger.log(
								fmt::format("File '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										QLogicaeCLI::configurations_folder_name /
										QLogicaeCLI::utilities_file_name
									).string()
								),
								QLogicaeCore::LogLevel::INFO
							);
						}
						else
						{
							QLogicaeCLI::timestamp_logger.log(
								fmt::format("File '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										QLogicaeCLI::configurations_folder_name /
										QLogicaeCLI::utilities_file_name
									).string()
								),
								QLogicaeCore::LogLevel::WARNING
							);
						}

						if (!std::filesystem::exists(
							_setup_default_template_input_1 /
							QLogicaeCLI::private_file_name
						))
						{
							std::filesystem::copy_file(
								QLogicaeCLI::application_directory /
								QLogicaeCLI::templates_folder_name /
								"default" /
								QLogicaeCLI::private_file_name,
								_setup_default_template_input_1 /
								QLogicaeCLI::private_file_name,
								std::filesystem::copy_options::overwrite_existing
							);
							QLogicaeCLI::timestamp_logger.log(
								fmt::format("File '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										QLogicaeCLI::private_file_name
									).string()
								),
								QLogicaeCore::LogLevel::INFO
							);
						}
						else
						{
							QLogicaeCLI::timestamp_logger.log(
								fmt::format("File '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										QLogicaeCLI::private_file_name
									).string()
								),
								QLogicaeCore::LogLevel::WARNING
							);
						}

						if (!std::filesystem::exists(
							_setup_default_template_input_1 /
							QLogicaeCLI::gitignore_file_name
						))
						{
							std::filesystem::copy_file(
								QLogicaeCLI::application_directory /
								QLogicaeCLI::templates_folder_name /
								"default" /
								QLogicaeCLI::gitignore_file_name,
								_setup_default_template_input_1 /
								QLogicaeCLI::gitignore_file_name,
								std::filesystem::copy_options::overwrite_existing
							);
							QLogicaeCLI::timestamp_logger.log(
								fmt::format("File '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										QLogicaeCLI::gitignore_file_name
									).string()
								),
								QLogicaeCore::LogLevel::INFO
							);
						}
						else
						{
							QLogicaeCLI::timestamp_logger.log(
								fmt::format("File '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										QLogicaeCLI::gitignore_file_name
									).string()
								),
								QLogicaeCore::LogLevel::WARNING
							);
						}

						if (!std::filesystem::exists(
							_setup_default_template_input_1 /
							QLogicaeCLI::license_file_name
						))
						{
							std::filesystem::copy_file(
								QLogicaeCLI::application_directory /
								QLogicaeCLI::templates_folder_name /
								"default" /
								QLogicaeCLI::license_file_name,
								_setup_default_template_input_1 /
								QLogicaeCLI::license_file_name,
								std::filesystem::copy_options::overwrite_existing
							);
							QLogicaeCLI::timestamp_logger.log(
								fmt::format("File '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										QLogicaeCLI::license_file_name
									).string()
								),
								QLogicaeCore::LogLevel::INFO
							);
						}
						else
						{
							QLogicaeCLI::timestamp_logger.log(
								fmt::format("File '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										QLogicaeCLI::license_file_name
									).string()
								),
								QLogicaeCore::LogLevel::WARNING
							);
						}

						if (!std::filesystem::exists(
							_setup_default_template_input_1 /
							QLogicaeCLI::scripts_folder_name /
							QLogicaeCLI::inno_run_file_name
						))
						{
							std::filesystem::copy_file(
								QLogicaeCLI::application_directory /
								QLogicaeCLI::templates_folder_name /
								"default" /
								QLogicaeCLI::inno_run_file_name,
								_setup_default_template_input_1 /
								QLogicaeCLI::scripts_folder_name /
								QLogicaeCLI::inno_run_file_name,
								std::filesystem::copy_options::overwrite_existing
							);
							QLogicaeCLI::timestamp_logger.log(
								fmt::format("File '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										QLogicaeCLI::scripts_folder_name /
										QLogicaeCLI::inno_run_file_name
									).string()
								),
								QLogicaeCore::LogLevel::INFO
							);
						}
						else
						{
							QLogicaeCLI::timestamp_logger.log(
								fmt::format("File '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										QLogicaeCLI::scripts_folder_name /
										QLogicaeCLI::inno_run_file_name
									).string()
								),
								QLogicaeCore::LogLevel::WARNING
							);
						}

						if (!std::filesystem::exists(
							_setup_default_template_input_1 /
							QLogicaeCLI::scripts_folder_name /
							QLogicaeCLI::inno_setup_file_name
						))
						{
							std::filesystem::copy_file(
								QLogicaeCLI::application_directory /
								QLogicaeCLI::templates_folder_name /
								"default" /
								QLogicaeCLI::inno_setup_file_name,
								_setup_default_template_input_1 /
								QLogicaeCLI::scripts_folder_name /
								QLogicaeCLI::inno_setup_file_name,
								std::filesystem::copy_options::overwrite_existing
							);
							QLogicaeCLI::timestamp_logger.log(
								fmt::format("File '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										QLogicaeCLI::scripts_folder_name /
										QLogicaeCLI::inno_setup_file_name
									).string()
								),
								QLogicaeCore::LogLevel::INFO
							);
						}
						else
						{
							QLogicaeCLI::timestamp_logger.log(
								fmt::format("File '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										QLogicaeCLI::scripts_folder_name /
										QLogicaeCLI::inno_setup_file_name
									).string()
								),
								QLogicaeCore::LogLevel::WARNING
							);
						}

						if (!std::filesystem::exists(
							_setup_default_template_input_1 /
							QLogicaeCLI::assets_folder_name /
							QLogicaeCLI::icon_file_name
						))
						{
							std::filesystem::copy_file(
								QLogicaeCLI::application_directory /
								QLogicaeCLI::templates_folder_name /
								"default" /
								QLogicaeCLI::icon_file_name,
								_setup_default_template_input_1 /
								QLogicaeCLI::assets_folder_name /
								QLogicaeCLI::icon_file_name,
								std::filesystem::copy_options::overwrite_existing
							);
							QLogicaeCLI::timestamp_logger.log(
								fmt::format("File '{}' created",
									std::filesystem::path(
										_setup_default_template_input_1 /
										QLogicaeCLI::assets_folder_name /
										QLogicaeCLI::icon_file_name
									).string()
								),
								QLogicaeCore::LogLevel::INFO
							);
						}
						else
						{
							QLogicaeCLI::timestamp_logger.log(
								fmt::format("File '{}' already exists",
									std::filesystem::path(
										_setup_default_template_input_1 /
										QLogicaeCLI::assets_folder_name /
										QLogicaeCLI::icon_file_name
									).string()
								),
								QLogicaeCore::LogLevel::WARNING
							);
						}

						QLogicaeCLI::timestamp_logger.log(
							"Complete!", QLogicaeCore::LogLevel::SUCCESS
						);
					}
					catch (const std::exception error)
					{
						QLogicaeCLI::timestamp_logger.log(
							error.what(), QLogicaeCore::LogLevel::EXCEPTION);

						return false;
					}

					return true;
				}
			);
			_commands["setup-default-template"].first
				->add_option("--target-root-project-directory", _setup_default_template_input_1, "")
				->default_val(".");



			_commands["verify-default-filesystem"] = std::make_pair(
				_application.add_subcommand(
					"verify-default-filesystem", ""),
				[this]() -> bool
				{
					try
					{
						if (_verify_default_template_input_1.empty())
						{
							return false;
						}

						QLogicaeCLI::timestamp_logger.log(
							"Running...",
							QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
						);

						std::vector<std::filesystem::path> file_paths =
						{
							std::filesystem::path(
								_verify_default_template_input_1 /
								QLogicaeCLI::scripts_folder_name /
								QLogicaeCLI::inno_run_file_name
							),
							std::filesystem::path(
								_verify_default_template_input_1 /
								QLogicaeCLI::scripts_folder_name /
								QLogicaeCLI::inno_setup_file_name
							),
							std::filesystem::path(
								_verify_default_template_input_1 /
								QLogicaeCLI::configurations_folder_name /
								QLogicaeCLI::utilities_file_name
							),
							std::filesystem::path(
								_verify_default_template_input_1 /
								QLogicaeCLI::configurations_folder_name /
								QLogicaeCLI::public_file_name
							),
							std::filesystem::path(
								_verify_default_template_input_1 /
								QLogicaeCLI::private_file_name
							),
							std::filesystem::path(
								_verify_default_template_input_1 /
								QLogicaeCLI::license_file_name
							),
							std::filesystem::path(
								_verify_default_template_input_1 /
								QLogicaeCLI::gitignore_file_name
							)
						};

						for (const auto& file_path : file_paths)
						{
							if (std::filesystem::exists(file_path))
							{
								QLogicaeCLI::timestamp_logger.log(
									fmt::format(
										"File '{}' exists",
										file_path.string()
									),
									QLogicaeCore::LogLevel::SUCCESS
								);
							}
							else
							{
								QLogicaeCLI::timestamp_logger.log(
									fmt::format(
										"File '{}' does not exist",
										file_path.string()
									),
									QLogicaeCore::LogLevel::EXCEPTION
								);
							}
						}

						QLogicaeCLI::timestamp_logger.log(
							"Complete!", QLogicaeCore::LogLevel::SUCCESS
						);
					}
					catch (const std::exception error)
					{
						QLogicaeCLI::timestamp_logger.log(
							error.what(), QLogicaeCore::LogLevel::EXCEPTION);

						return false;
					}

					return true;
				}
			);
			_commands["verify-default-filesystem"].first
				->add_option("--target-root-project-directory", _verify_default_template_input_1, "")
				->default_val(".");



			_commands["setup-installer"] = std::make_pair(
				_application.add_subcommand(
					"setup-installer", ""),
				[this]() -> bool
				{
					try
					{
						QLogicaeCLI::timestamp_logger.log(
							"Running...",
							QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
						);

						QLogicaeCLI::client_public_file.set_file_path(
							std::filesystem::path(
								_setup_installer_input_1 /
								QLogicaeCLI::configurations_folder_name /
								QLogicaeCLI::public_file_name
							).string()
						);
						QLogicaeCLI::client_private_file.set_file_path(
							std::filesystem::path(
								_setup_installer_input_1 /
								QLogicaeCLI::private_file_name
							).string()
						);
						QLogicaeCLI::client_inno_run_file.set_file_path(
							std::filesystem::path(
								_setup_installer_input_1 /
								QLogicaeCLI::scripts_folder_name /
								QLogicaeCLI::inno_run_file_name
							).string()
						);
						QLogicaeCLI::client_inno_setup_file.set_file_path(
							std::filesystem::path(
								_setup_installer_input_1 /
								QLogicaeCLI::scripts_folder_name /
								QLogicaeCLI::inno_setup_file_name
							).string()
						);
						QLogicaeCLI::client_inno_setup_target_file.set_file_path(
							std::filesystem::path(
								_setup_installer_input_1 /
								QLogicaeCLI::scripts_folder_name /
								QLogicaeCLI::inno_setup_target_file_name
							).string()
						);
						QLogicaeCLI::client_utilities_file.set_file_path(
							std::filesystem::path(
								_setup_installer_input_1 /
								QLogicaeCLI::configurations_folder_name /
								QLogicaeCLI::utilities_file_name
							).string()
						);

						std::filesystem::path input_folder_path = std::filesystem::absolute(
							QLogicaeCLI::client_utilities_file.get_string({ "inno_setup", "input_folder_path" })
						);
						std::filesystem::path output_folder_path = std::filesystem::absolute(
							QLogicaeCLI::client_utilities_file.get_string({ "inno_setup", "output_folder_path" })
						);
						
						QLogicaeCLI::client_utilities_file.set_file_path(
							std::filesystem::path(
								input_folder_path /
								QLogicaeCLI::configurations_folder_name /
								QLogicaeCLI::utilities_file_name
							).string()
						);
						QLogicaeCLI::client_utilities_file.update_string(
							{ "environment", "selected" }, "release"
						);
						QLogicaeCLI::client_utilities_file.set_file_path(
							std::filesystem::path(
								_setup_installer_input_1 /
								QLogicaeCLI::configurations_folder_name /
								QLogicaeCLI::utilities_file_name
							).string()
						);

						if (!std::filesystem::exists(
							_setup_installer_input_1 /
							QLogicaeCLI::scripts_folder_name
						))
						{
							std::filesystem::create_directory(
								_setup_installer_input_1 /
								QLogicaeCLI::scripts_folder_name
							);
						}

						if (std::filesystem::exists(
							_setup_installer_input_1 /
							QLogicaeCLI::scripts_folder_name /
							QLogicaeCLI::inno_setup_target_file_name)
							)
						{
							std::filesystem::remove(
								_setup_installer_input_1 /
								QLogicaeCLI::scripts_folder_name /
								QLogicaeCLI::inno_setup_target_file_name
							);
						}

						std::filesystem::copy_file(
							_setup_installer_input_1 /
							QLogicaeCLI::scripts_folder_name /
							QLogicaeCLI::inno_setup_file_name,
							_setup_installer_input_1 /
							QLogicaeCLI::scripts_folder_name /
							QLogicaeCLI::inno_setup_target_file_name,
							std::filesystem::copy_options::overwrite_existing
						);

						std::unordered_map<std::string, std::any> languages =
							QLogicaeCLI::client_utilities_file.get_object(
								{ "languages" }
							);
						QLogicaeCLI::client_inno_setup_target_file.append(
							"\n[Languages]\n"
						);
						for (const auto& [name, properties] : languages)
						{
							std::unordered_map<std::string, std::any> object =
								std::any_cast<std::unordered_map<
									std::string, std::any>>(properties);
							if (std::any_cast<bool>(object["is_enabled"]))
							{
								QLogicaeCLI::client_inno_setup_target_file.append(
									fmt::format("Name: \"{}\"; MessagesFile: \"{}\"\n",
										name,
										std::any_cast<std::string>(
											object["message_file"]
										))
								);
							}
						}

						std::unordered_map<std::string, std::any>
							hkcu_secrets =
							QLogicaeCLI::client_private_file.get_object(
								{
									"windows_registry",
									"release",
									"hkcu"
								}
							);
						std::string application_id =
							QLogicaeCLI::client_public_file
							.get_string(
								{
									"application",
									"id"
								}
							);
						std::string release_id =
							QLogicaeCLI::client_utilities_file
							.get_string(
								{
									"environment",
									"selections",
									"release"
								}
							);
						QLogicaeCLI::client_inno_setup_target_file.append(
							"\n[Registry]\n"
						);
						for (const auto& [key, value] : hkcu_secrets)
						{
							std::string command = fmt::format(
								"Root: HKCU; Subkey: \"Software\\{}\\{}\"; ValueType: string; ValueName: \"{}\"; ValueData: \"{}\"; Flags: uninsdeletekeyifempty\n",
								application_id,
								release_id,
								std::any_cast<std::string>(key),
								std::any_cast<std::string>(value));
							QLogicaeCLI::client_inno_setup_target_file.append(
								command
							);
						}

						system(
							fmt::format(
								"powershell -ExecutionPolicy Bypass -File \"{}\"",
								std::filesystem::path(
									_setup_installer_input_1 /
									QLogicaeCLI::scripts_folder_name /
									QLogicaeCLI::inno_run_file_name
								).string()
							).c_str()
						);

						if (std::filesystem::exists(
							_setup_installer_input_1 /
							QLogicaeCLI::temporary_folder_name
						))
						{
							std::filesystem::remove_all(
								_setup_installer_input_1 /
								QLogicaeCLI::temporary_folder_name
							);
						}
						
						QLogicaeCLI::client_utilities_file.update_string(
							{ "environment", "selected" }, "development"
						);
						QLogicaeCLI::client_utilities_file.update_string(
							{ "environment", "selections", "development" },	
							QLogicaeCLI::generator.random_uuid4()
						);
						QLogicaeCLI::client_utilities_file.update_string(
							{ "environment", "selections", "debug" },
							QLogicaeCLI::generator.random_uuid4()
						);
						QLogicaeCLI::client_utilities_file.update_string(
							{ "environment", "selections", "test" },
							QLogicaeCLI::generator.random_uuid4()
						);
						QLogicaeCLI::client_utilities_file.update_string(
							{ "environment", "selections", "release" },
							QLogicaeCLI::generator.random_uuid4()
						);
						QLogicaeCLI::client_public_file.update_string(
							{ "application", "id" },
							QLogicaeCLI::generator.random_uuid4()
						);

						QLogicaeCLI::timestamp_logger.log(
							"Complete!", QLogicaeCore::LogLevel::SUCCESS
						);
					}
					catch (const std::exception error)
					{
						QLogicaeCLI::timestamp_logger.log(
							error.what(), QLogicaeCore::LogLevel::EXCEPTION);

						return false;
					}

					return true;
				}
			);
			_commands["setup-installer"].first
				->add_option("--target-project-folder", _setup_installer_input_1, "")
				->default_val(".");
			_commands["setup-installer"].first
				->add_option("--output-directory", _setup_installer_input_2, "")
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
