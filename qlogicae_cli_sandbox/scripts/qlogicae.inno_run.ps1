$private_configurations = Get-Content qlogicae.private.json | ConvertFrom-Json
$public_configurations = Get-Content configurations/qlogicae.public.json -Raw | ConvertFrom-Json
$utilities_configurations = Get-Content configurations/qlogicae.utilities.json -Raw | ConvertFrom-Json

& $utilities_configurations.inno_setup.cli_path`
    /DMyAppId="$($public_configurations.application.id)" `
    /DMyAppName="$($public_configurations.application.name)" `
    /DMyAppVersion="$($public_configurations.application.version)" `
    /DMyAppPublisher="$($public_configurations.application.company)" `
    /DMyAppURL="$($public_configurations.application.url)" `
    /DMyAppExeName="$($public_configurations.application.alias).exe" `
    /DMyLicenseFile="$(Get-Location)\$($utilities_configurations.application.license_path)" `
    /DMyOutputBaseFilename="$($public_configurations.application.alias)_$($public_configurations.application.version)_$($public_configurations.application.architecture)_Setup" `
    /DMySetupIconFile="$(Get-Location)\$($utilities_configurations.application.icon_path)" `
    /DMyOutputDir="$($utilities_configurations.inno_setup.output_folder_path)" `
    /DMyAppExeSource="$($utilities_configurations.inno_setup.input_folder_path)\$($public_configurations.application.alias).exe" `
    /DMyAppFolderSource="$($utilities_configurations.inno_setup.input_folder_path)" `
    $utilities_configurations.inno_setup.template_path
