param(
    [string]$ScriptPath
)

. $PSScriptRoot/qlogicae/kmand/scripts/imports.ps1

$QLogicaeKmandInstance.Setup($ScriptPath)

Invoke-Pester -Configuration $QLogicaeKmandInstance.Configurations.PesterConfigurations *>&1 | Tee-Object -FilePath $QLogicaeKmandInstance.Configurations.DotQLogicaeLogsPesterConsoleFile
