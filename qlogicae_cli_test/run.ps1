param(
    [string]$ScriptPath
)

. $PSScriptRoot/qlogicae/kmand/scripts/imports.ps1

$QLogicaeKmandInstance.Setup($ScriptPath)

Invoke-Pester -Configuration $QLogicaeKmandInstance.Configurations.PesterConfigurations *>&1 | Tee-Object -FilePath $QLogicaeKmandInstance.Configurations.DotQLogicaeLogsPesterConsoleFile

<#

function Merge-JsonFiles {
    param(
        [string[]]$Paths,
        [string]$OutputPath,
        [int]$TabsPerLevel = 2
    )

    if ($Paths.Count -lt 2) {
        throw "Please provide at least two JSON files."
    }

    $quotedFiles = $Paths | ForEach-Object { "`"$_`"" }
    $files = $quotedFiles -join " "

    $cmd = "jq -s --indent $TabsPerLevel -f deepmerge.jq $files > `"$OutputPath`""

    Write-Host "Merging JSON files: $files"
    Write-Host "Output: $OutputPath"

    cmd /c $cmd
}

Merge-JsonFiles -Paths @(".\first.json", ".\second.json") -OutputPath ".\merged.json" -TabsPerLevel 4

#>

