$global:QLogicaePesterTest_IsConsoleLoggingEnabled = $true
$global:QLogicaePesterTest_IsFileLoggingEnabled = $true

$global:QLogicaePesterTest_UUID4Pattern = "[0-9a-f]{8}-[0-9a-f]{4}-4[0-9a-f]{3}-[89ab][0-9a-f]{3}-[0-9a-f]{12}"

$global:QLogicaePesterTest_DotQLogicaeFolderPath = ".qlogicae"
$global:QLogicaePesterTest_DotQLogicaeCLIFolderPath = ".qlogicae/cli"
$global:QLogicaePesterTest_DotQLogicaeLogsFolderPath = ".qlogicae/logs"
$global:QLogicaePesterTest_DotQLogicaeLogsPesterFolderPath = ".qlogicae/logs/pester"
$global:QLogicaePesterTest_DotQLogicaeLogsPesterJUnitFile = ".qlogicae/logs/pester/junit.xml"
$global:QLogicaePesterTest_DotQLogicaeLogsPesterNUnitFile = ".qlogicae/logs/pester/nunit.xml"
$global:QLogicaePesterTest_DotQLogicaeLogsPesterCoverageFile = ".qlogicae/logs/pester/coverage.xml"
$global:QLogicaePesterTest_DotQLogicaeLogsPesterConsoleFile = ".qlogicae/logs/pester/console.txt"

$global:QLogicaePesterTest_DotQLogicaeCLICustomOutputFilePath = ".qlogicae/cli/custom_output.txt"
$global:QLogicaePesterTest_DotQLogicaeCLIDefaultOutputFilePath = ".qlogicae/cli/default_output.txt"

$global:QLogicaePesterTest_IsConfigurationsSetup = $false
$global:QLogicaePesterTest_Configurations = [PesterConfiguration]::Default

function QLogicaePesterTest_GlobalTestsSetup {    
    param(
        [string]$ScriptPath
    )

    if ($global:QLogicaePesterTest_IsConfigurationsSetup) {
        Write-Host "Exception at QLogicaePesterTest_GlobalTestsSetup: Already Called"

        Exit 1
    }

    QLogicaePesterTest_CreateFolderTree -Path $global:QLogicaePesterTest_DotQLogicaeFolderPath
    QLogicaePesterTest_CreateFolderTree -Path $global:QLogicaePesterTest_DotQLogicaeCLIFolderPath
    QLogicaePesterTest_CreateFolderTree -Path $global:QLogicaePesterTest_DotQLogicaeLogsFolderPath
    QLogicaePesterTest_CreateFolderTree -Path $global:QLogicaePesterTest_DotQLogicaeLogsPesterFolderPath

    $global:QLogicaePesterTest_Configurations.Run.Path = $ScriptPath
    $global:QLogicaePesterTest_Configurations.Output.Verbosity = 'Diagnostic'
    $global:QLogicaePesterTest_Configurations.Should.ErrorAction = 'Continue'

    $global:QLogicaePesterTest_Configurations.CodeCoverage.Enabled = $true
    if ($global:QLogicaePesterTest_Configurations.CodeCoverage.Enabled) {
        $global:QLogicaePesterTest_Configurations.CodeCoverage.OutputPath = $global:QLogicaePesterTest_DotQLogicaeLogsPesterCoverageFile
    }    
    
    $global:QLogicaePesterTest_Configurations.Debug.ShowFullErrors = $true
    $global:QLogicaePesterTest_Configurations.Debug.WriteDebugMessages = $true

    if ($global:QLogicaePesterTest_IsFileLoggingEnabled) {
        $global:QLogicaePesterTest_Configurations.TestResult.Enabled = $true
        $global:QLogicaePesterTest_Configurations.TestResult.OutputPath  = $global:QLogicaePesterTest_DotQLogicaeLogsPesterNUnitFile
        $global:QLogicaePesterTest_Configurations.TestResult.OutputFormat = "NUnitXml"        
    }

    $global:QLogicaePesterTest_IsConfigurationsSetup = $true
}

function QLogicaePesterTest_BeforeAllTestsSetup {    
    QLogicaePesterTest_ClearFolder -Path $global:QLogicaePesterTest_DotQLogicaeCLIFolderPath
}

function QLogicaePesterTest_AfterAllTestsSetup {
    QLogicaePesterTest_ClearFolder -Path $global:QLogicaePesterTest_DotQLogicaeCLIFolderPath
}

function QLogicaePesterTest_ClearFolder {
    param(
        [AllowEmptyString()][AllowNull()][string]$Path
    )
    
    if ([string]::IsNullOrEmpty($Path)) {
        return
    }

    Get-ChildItem -Path $Path -Recurse -Force | Remove-Item -Recurse -Force
}

function QLogicaePesterTest_CreateFolderTree {
    param(
        [AllowEmptyString()][AllowNull()][string]$Path
    )

    if ([string]::IsNullOrEmpty($Path)) {
        return
    }

    if (-not (Test-Path $Path)) {
        New-Item -Path $Path -ItemType Directory -Force | Out-Null
    }
}

function QLogicaePesterTest_ConsoleLog {
    param(
        [AllowEmptyString()][AllowNull()][string]$Text,
        [bool]$IsConsoleLoggingEnabled = $global:QLogicaePesterTest_IsConsoleLoggingEnabled,
        [bool]$IsFileLoggingEnabled = $global:QLogicaePesterTest_IsFileLoggingEnabled
    )

    if ([string]::IsNullOrEmpty($Text)) {
        return
    }

    if ($IsConsoleLoggingEnabled) {
        Write-Host $Text
    }
}

function QLogicaePesterTest_GetLineCount {
    param(
        [AllowEmptyString()][AllowNull()][string]$Text
    )
    
    $lines = ($Text -split "`r?`n") | Where-Object { $_.Trim() -ne "" }

    return $lines.Count
}

function QLogicaePesterTest_GetPatternMatchCount {
    param(
        [AllowEmptyString()][AllowNull()][string]$Text,
        [AllowEmptyString()][AllowNull()][string]$Pattern,
        [AllowEmptyString()][AllowNull()][string]$CaseSensitivity = 'IgnoreCase'
    )

    $matches = [regex]::Matches($Text, $Pattern, $CaseSensitivity)
    
    return $matches.Count
}

function QLogicaePesterTest_GetUUIDv4Count {
    param(
        [AllowEmptyString()][AllowNull()][string]$Text
    )

    $matches = [regex]::Matches($Text, $global:QLogicaePesterTest_UUID4Pattern, 'IgnoreCase')
    
    return $matches.Count
}
