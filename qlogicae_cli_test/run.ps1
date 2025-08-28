param(
    [string]$ScriptPath
)

. $PSScriptRoot/imports.ps1

$QlogicaeKmandInstance.Setup($ScriptPath)

Invoke-Pester -Configuration $QlogicaeKmandInstance.Configurations.PesterConfigurations *>&1 | Tee-Object -FilePath $QlogicaeKmandInstance.Configurations.DotQLogicaeLogsPesterConsoleFile
