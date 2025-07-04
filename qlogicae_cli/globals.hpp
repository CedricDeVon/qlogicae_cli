#pragma once

#include "pch.hpp"

namespace ErwinCLI
{
    static std::filesystem::path application_directory = Erwin::SystemAccess::instance().get_executable_dir();
    static std::filesystem::path public_file_name = "erwin.public.json";
    static std::filesystem::path gitignore_file_name = "erwin.gitignore";
    static std::filesystem::path private_file_name = "erwin.private.json";
    static std::filesystem::path utilities_file_name = "erwin.utilities.json";
    static std::filesystem::path license_file_name = "LICENSE.txt";
    static std::filesystem::path icon_file_name = "icon.ico";
    static std::filesystem::path inno_run_file_name = "erwin.inno_run.ps1";
    static std::filesystem::path inno_setup_file_name = "erwin.inno_setup.iss";
    static std::filesystem::path inno_run_target_file_name = "erwin.inno_run.target.ps1";
    static std::filesystem::path inno_setup_target_file_name = "erwin.inno_setup.target.iss";

    static std::filesystem::path assets_folder_name = "assets";
    static std::filesystem::path templates_folder_name = "templates";
    static std::filesystem::path temporary_folder_name = "temporary";
    static std::filesystem::path scripts_folder_name = "scripts";
    static std::filesystem::path configurations_folder_name = "configurations";

    static std::filesystem::path application_public_file_path = ErwinCLI::application_directory / ErwinCLI::configurations_folder_name / ErwinCLI::public_file_name;
    static std::filesystem::path application_utilities_file_path = ErwinCLI::application_directory / ErwinCLI::configurations_folder_name / ErwinCLI::utilities_file_name;

    static Erwin::Cryptographer1 cryptographer_1;
    static Erwin::Cryptographer2 cryptographer_2;
    static Erwin::Cryptographer3 cryptographer_3;
    static Erwin::Cryptographer4 cryptographer_4;

    static Erwin::Logger timestamp_logger;
    static Erwin::CliIO& raw_logger = Erwin::CliIO::instance();
    static Erwin::Generator& generator = Erwin::Generator::instance();

    static Erwin::TextFileIO client_inno_run_file;
    static Erwin::TextFileIO client_inno_setup_file;
    static Erwin::TextFileIO client_inno_run_target_file;
    static Erwin::TextFileIO client_inno_setup_target_file;

    static Erwin::JsonFileIO client_public_file;
    static Erwin::JsonFileIO client_private_file;
    static Erwin::JsonFileIO client_utilities_file;
    static Erwin::JsonFileIO application_public_file(ErwinCLI::application_public_file_path.string());
    static Erwin::JsonFileIO application_utilities_file(ErwinCLI::application_utilities_file_path.string());

    static std::string application_id = ErwinCLI::application_public_file.get_string({ "application", "id" });
    static std::string application_name = ErwinCLI::application_public_file.get_string({ "application", "name" });
    static std::string application_version = ErwinCLI::application_public_file.get_string({ "application", "version" });
    static std::string application_company = ErwinCLI::application_public_file.get_string({ "application", "company" });
    static std::string application_authors = ErwinCLI::application_public_file.get_string({ "application", "authors" });
    static std::string application_description = ErwinCLI::application_public_file.get_string({ "application", "description" });

    static std::string utilities_environment_selected = ErwinCLI::application_utilities_file.get_string({ "environment", "selected" });
    static std::vector<std::string> utilities_environment_types { "development", "debug", "test", "release" };
    static std::vector<std::string> utilities_environment_types_options { "development", "debug", "test", "release", "all"};
    static std::vector<std::string> utilities_setup_template_types { "default", "custom" };

    static std::string application_full_name = fmt::format("{} ({})",
        application_name, application_version
    );
}
