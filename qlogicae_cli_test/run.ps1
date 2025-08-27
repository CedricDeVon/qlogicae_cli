param(
    [string]$ScriptPath
)

. $PSScriptRoot/imports.ps1

QLogicaePesterTest_GlobalTestsSetup -ScriptPath $ScriptPath

Invoke-Pester -Configuration $global:QLogicaePesterTest_Configurations *>&1 | Tee-Object -FilePath $global:QLogicaePesterTest_DotQLogicaeLogsPesterConsoleFile
