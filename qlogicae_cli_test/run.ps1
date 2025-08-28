param(
    [string]$ScriptPath
)

. $PSScriptRoot/imports.ps1

QLogicaeKmand_GlobalTestsSetup -ScriptPath $ScriptPath

Invoke-Pester -Configuration $QLogicaeKmand_Configurations.PesterConfigurations *>&1 | Tee-Object -FilePath $QLogicaeKmand_Configurations.DotQLogicaeLogsPesterConsoleFile
