
if (-not $QLogicaeKmand_Configurations) {
    $QLogicaeKmand_Configurations = [pscustomobject]@{}
}

$script:QLogicaeKmand_Configurations = [PSCustomObject]@{
    IsConsoleLoggingEnabled = $true
    IsFileLoggingEnabled    = $true

    UUID4Pattern = "[0-9a-f]{8}-[0-9a-f]{4}-4[0-9a-f]{3}-[89ab][0-9a-f]{3}-[0-9a-f]{12}"

    DotQlogicaeFolderPath = ".qlogicae"
    DotQlogicaeCLIFolderPath = ".qlogicae/cli"
    DotQlogicaeLogsFolderPath = ".qlogicae/logs"
    DotQlogicaeLogsPesterFolderPath = ".qlogicae/logs/pester"
    DotQlogicaeLogsPesterJUnitFile = ".qlogicae/logs/pester/junit.xml"
    DotQlogicaeLogsPesterNUnitFile = ".qlogicae/logs/pester/nunit.xml"
    DotQlogicaeLogsPesterCoverageFile = ".qlogicae/logs/pester/coverage.xml"
    DotQlogicaeLogsPesterConsoleFile = ".qlogicae/logs/pester/console.txt"
    DotQlogicaeCLICustomOutputFilePath = ".qlogicae/cli/custom_output.txt"
    DotQlogicaeCLIDefaultOutputFilePath = ".qlogicae/cli/default_output.txt"

    IsConfigurationsSetup = $false
    PesterConfigurations = @{
        Run = @{
            Path = $PSScriptRoot
        }
        Output = @{
            Verbosity = 'Detailed'
        }
        Should = @{
            ErrorAction = 'Continue'
        }
        CodeCoverage = @{
            Enabled = $true
            OutputFormat = 'CoverageGutters'
            OutputPath = $QLogicaeKmand_Configurations.DotQLogicaeLogsPesterCoverageFile
        }
        Debug = @{
            ShowFullErrors = $true
            WriteDebugMessages = $true
        }
        TestResult = @{
            Enabled = $true
            OutputPath = $QLogicaeKmand_Configurations.DotQLogicaeLogsPesterNUnitFile
            OutputFormat = "NUnitXml"
        }
    }
}


function QLogicaeKmand_GlobalTestsSetup {
    param(
        [string]$ScriptPath
    )
    
    if ($QLogicaeKmand_Configurations.IsConfigurationsSetup) {
        Write-Information "Exception at QLogicaeKmand_GlobalTestsSetup: Already Called"

        Exit 1
    }

    QLogicaeKmand_CreateFolderTree -Path $QLogicaeKmand_Configurations.DotQLogicaeFolderPath
    QLogicaeKmand_CreateFolderTree -Path $QLogicaeKmand_Configurations.DotQLogicaeCLIFolderPath
    QLogicaeKmand_CreateFolderTree -Path $QLogicaeKmand_Configurations.DotQLogicaeLogsFolderPath
    QLogicaeKmand_CreateFolderTree -Path $QLogicaeKmand_Configurations.DotQLogicaeLogsPesterFolderPath

    $QLogicaeKmand_Configurations.PesterConfigurations.Run.Path = $ScriptPath
    
    $QLogicaeKmand_Configurations.IsConfigurationsSetup = $true
}

function QLogicaeKmand_BeforeAllTestsSetup {
    QLogicaeKmand_ClearFolder -Path $QLogicaeKmand_Configurations.DotQLogicaeCLIFolderPath
}

function QLogicaeKmand_AfterAllTestsSetup {
    QLogicaeKmand_ClearFolder -Path $QLogicaeKmand_Configurations.DotQLogicaeCLIFolderPath
}

function QLogicaeKmand_ClearFolder {
    param(
        [AllowEmptyString()][AllowNull()][string]$Path
    )

    if ([string]::IsNullOrEmpty($Path)) {
        return
    }

    Get-ChildItem -Path $Path -Recurse -Force | Remove-Item -Recurse -Force
}

function QLogicaeKmand_CreateFolderTree {
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

function QLogicaeKmand_ConsoleLog {
    param(
        [AllowEmptyString()][AllowNull()][string]$Text,
        [bool]$IsConsoleLoggingEnabled = $QLogicaeKmand_Configurations.IsConsoleLoggingEnabled
    )

    if ([string]::IsNullOrEmpty($Text)) {
        return
    }

    if ($IsConsoleLoggingEnabled) {
        Write-Information $Text
    }
}

function QLogicaeKmand_GetLineCount {
    param(
        [AllowEmptyString()][AllowNull()][string]$Text
    )

    $lines = ($Text -split "`r?`n") | Where-Object { $_.Trim() -ne "" }

    return $lines.Count
}

function QLogicaeKmand_GetPatternMatchCount {
    param(
        [AllowEmptyString()][AllowNull()][string]$Text,
        [AllowEmptyString()][AllowNull()][string]$Pattern,
        [AllowEmptyString()][AllowNull()][string]$CaseSensitivity = 'IgnoreCase'
    )

    $regexMatches = [regex]::Matches($Text, $Pattern, $CaseSensitivity)

    return $regexMatches.Count
}

function QLogicaeKmand_GetUUIDv4Count {
    param(
        [AllowEmptyString()][AllowNull()][string]$Text
    )

    $regexMatches = [regex]::Matches($Text, $QLogicaeKmand_Configurations.UUID4Pattern, 'IgnoreCase')

    return $regexMatches.Count
}

<#
class QLogicaeKmand {
    hidden static [QLogicaeKmand]$Instance
    static [PSCustomObject]$Configurations = [PSCustomObject]@{
        IsConsoleLoggingEnabled = $true
        IsFileLoggingEnabled    = $true

        UUID4Pattern = "[0-9a-f]{8}-[0-9a-f]{4}-4[0-9a-f]{3}-[89ab][0-9a-f]{3}-[0-9a-f]{12}"

        DotQlogicaeFolderPath = ".qlogicae"
        DotQlogicaeCLIFolderPath = ".qlogicae/cli"
        DotQlogicaeLogsFolderPath = ".qlogicae/logs"
        DotQlogicaeLogsPesterFolderPath = ".qlogicae/logs/pester"
        DotQlogicaeLogsPesterJUnitFile = ".qlogicae/logs/pester/junit.xml"
        DotQlogicaeLogsPesterNUnitFile = ".qlogicae/logs/pester/nunit.xml"
        DotQlogicaeLogsPesterCoverageFile = ".qlogicae/logs/pester/coverage.xml"
        DotQlogicaeLogsPesterConsoleFile = ".qlogicae/logs/pester/console.txt"
        DotQlogicaeCLICustomOutputFilePath = ".qlogicae/cli/custom_output.txt"
        DotQlogicaeCLIDefaultOutputFilePath = ".qlogicae/cli/default_output.txt"

        IsConfigurationsSetup = $false
        PesterConfigurations = [PesterConfiguration]::Default
    }

    hidden QLogicaeKmand() {}

    static [QLogicaeKmand] GetInstance() {
        if (-not [QLogicaeKmand]::Instance) {
            [QLogicaeKmand]::Instance = [QLogicaeKmand]::new()
        }
        return [QLogicaeKmand]::Instance
    }

    [void] SayHello() {
        Write-Host "Hello from QLogicaeKmand!"
    }

    [void] GlobalTestsSetup([string]$ScriptPath) {
        if ([QLogicaeKmand]::Configurations.IsConfigurationsSetup) {
            Write-Information "Exception at GlobalTestsSetup: Already Called"
            Exit 1
        }

        $this.CreateFolderTree([QLogicaeKmand]::Configurations.DotQlogicaeFolderPath)
        $this.CreateFolderTree([QLogicaeKmand]::Configurations.DotQlogicaeCLIFolderPath)
        $this.CreateFolderTree([QLogicaeKmand]::Configurations.DotQlogicaeLogsFolderPath)
        $this.CreateFolderTree([QLogicaeKmand]::Configurations.DotQlogicaeLogsPesterFolderPath)

        $cfg = [QLogicaeKmand]::Configurations
        $cfg.PesterConfigurations.Run.Path = $ScriptPath
        $cfg.PesterConfigurations.Output.Verbosity = 'Diagnostic'
        $cfg.PesterConfigurations.Should.ErrorAction = 'Continue'
        $cfg.PesterConfigurations.CodeCoverage.Enabled = $true
        $cfg.PesterConfigurations.CodeCoverage.OutputPath = $cfg.DotQlogicaeLogsPesterCoverageFile
        $cfg.PesterConfigurations.Debug.ShowFullErrors = $true
        $cfg.PesterConfigurations.Debug.WriteDebugMessages = $true

        if ($cfg.IsFileLoggingEnabled) {
            $cfg.PesterConfigurations.TestResult.Enabled = $true
            $cfg.PesterConfigurations.TestResult.OutputPath = $cfg.DotQlogicaeLogsPesterNUnitFile
            $cfg.PesterConfigurations.TestResult.OutputFormat = "NUnitXml"
        }

        $cfg.IsConfigurationsSetup = $true
    }

    [void] BeforeAllTestsSetup() {
        $this.ClearFolder([QLogicaeKmand]::Configurations.DotQlogicaeCLIFolderPath)
    }

    [void] AfterAllTestsSetup() {
        $this.ClearFolder([QLogicaeKmand]::Configurations.DotQlogicaeCLIFolderPath)
    }

    [void] ClearFolder([string]$Path) {
        if ([string]::IsNullOrEmpty($Path)) { return }
        Get-ChildItem -Path $Path -Recurse -Force | Remove-Item -Recurse -Force
    }

    [void] CreateFolderTree([string]$Path) {
        if ([string]::IsNullOrEmpty($Path)) { return }
        if (-not (Test-Path $Path)) { New-Item -Path $Path -ItemType Directory -Force | Out-Null }
    }

    [void] ConsoleLog([string]$Text, [bool]$IsConsoleLoggingEnabled = $null) {
        if ([string]::IsNullOrEmpty($Text)) { return }
        if ($null -eq $IsConsoleLoggingEnabled) { $IsConsoleLoggingEnabled = [QLogicaeKmand]::Configurations.IsConsoleLoggingEnabled }
        if ($IsConsoleLoggingEnabled) { Write-Information $Text }
    }

    [int] GetLineCount([string]$Text) {
        return ($Text -split "`r?`n" | Where-Object { $_.Trim() -ne "" }).Count
    }

    [int] GetPatternMatchCount([string]$Text, [string]$Pattern, [string]$CaseSensitivity = 'IgnoreCase') {
        return ([regex]::Matches($Text, $Pattern, $CaseSensitivity)).Count
    }

    [int] GetUUIDv4Count([string]$Text) {
        return ([regex]::Matches($Text, [QLogicaeKmand]::Configurations.UUID4Pattern, 'IgnoreCase')).Count
    }
}

$script:QlogicaeKmandInstance = [QLogicaeKmand]::GetInstance()


#>