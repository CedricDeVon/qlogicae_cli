param(
    [string]$ScriptPath
)

. $PSScriptRoot/imports.ps1

$QLogicaeKmandInstance.Setup($ScriptPath)

Invoke-Pester -Configuration $QLogicaeKmandInstance.Configurations.PesterConfigurations *>&1 | Tee-Object -FilePath $QLogicaeKmandInstance.Configurations.DotQLogicaeLogsPesterConsoleFile
