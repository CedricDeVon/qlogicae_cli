$private_configurations = Get-Content .qlogicae/application/configurations/qlogicae.private.json | ConvertFrom-Json
$public_configurations = Get-Content qlogicae/application/configurations/qlogicae.public.json -Raw | ConvertFrom-Json

& $private_configurations.inno_setup.cli_executable_path`
    /DMyAppId="$($public_configurations.application.id)" `
    /DMyAppName="$($public_configurations.application.name)" `
    /DMyAppVersion="$($public_configurations.application.version)" `
    /DMyAppPublisher="$($public_configurations.application.company)" `
    /DMyAppURL="$($public_configurations.application.url)" `
    /DMyAppExeName="$($private_configurations.application.executable_name)" `
    /DMyLicenseFile="$(Get-Location)\$($private_configurations.application.license_file_path)" `
    /DMyOutputBaseFilename="$($public_configurations.application.name)_$($public_configurations.application.version)_$($public_configurations.application.architecture)_Setup" `
    /DMySetupIconFile="$(Get-Location)\$($private_configurations.application.icon_file_path)" `
    /DMyOutputDir="$($private_configurations.inno_setup.output_folder_path)" `
    /DMyAppExeSource="$($private_configurations.inno_setup.input_folder_path)\$($private_configurations.application.executable_name)" `
    /DMyAppFolderSource="$($private_configurations.inno_setup.input_folder_path)" `
    /DMyAppPrivilegesRequired="$($private_configurations.inno_setup.privileges_required)" `
    $private_configurations.inno_setup.template_file_path
