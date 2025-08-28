
class QLogicaeKmand {
    hidden static [QLogicaeKmand]$Instance
    [PSCustomObject]$Configurations

    hidden QLogicaeKmand() {
        $this.Configurations = [PSCustomObject]@{
            IsConsoleLoggingEnabled = $true
            IsFileLoggingEnabled    = $true

            UUID4Pattern = "[0-9a-f]{8}-[0-9a-f]{4}-4[0-9a-f]{3}-[89ab][0-9a-f]{3}-[0-9a-f]{12}"

            DotQlogicaeFolderPath = ".qlogicae"
            DotQlogicaeCLIFolderPath = ".qlogicae/cli"
            DotQlogicaeLogsFolderPath = ".qlogicae/logs"
            DotQlogicaeLogsPesterFolderPath = ".qlogicae/logs/pester"
            DotQlogicaeLogsPesterJUnitFile = ".qlogicae/logs/pester/junit.xml"          
            DotQlogicaeLogsPesterConsoleFile = ".qlogicae/logs/pester/console.txt"
            DotQlogicaeCLICustomOutputFilePath = ".qlogicae/cli/custom_output.txt"
            DotQlogicaeCLIDefaultOutputFilePath = ".qlogicae/cli/default_output.txt"

            PesterConfigurations = @{
                Run = @{
                    Path = ""
                }
                Output = @{
                    Verbosity = "Detailed"
                }
                Should = @{
                    ErrorAction = "Continue"
                }
                CodeCoverage = @{
                    Enabled = $true
                    OutputFormat = "CoverageGutters"
                    OutputPath = ".qlogicae/logs/pester/coverage.xml"
                }
                Debug = @{
                    ShowFullErrors = $true
                    WriteDebugMessages = $true
                }
                TestResult = @{
                    Enabled = $true
                    OutputPath = ".qlogicae/logs/pester/nunit.xml"
                    OutputFormat = "NUnitXml"
                }
            }
        }
    }

    static [QLogicaeKmand] GetInstance() {
        if (-not [QLogicaeKmand]::Instance) {
            [QLogicaeKmand]::Instance = [QLogicaeKmand]::new()
        }

        return [QLogicaeKmand]::Instance
    }

    [void] Setup([string]$ScriptPath) {
        $this.CreateFolderTree($this.Configurations.DotQlogicaeFolderPath)
        $this.CreateFolderTree($this.Configurations.DotQlogicaeCLIFolderPath)
        $this.CreateFolderTree($this.Configurations.DotQlogicaeLogsFolderPath)
        $this.CreateFolderTree($this.Configurations.DotQlogicaeLogsPesterFolderPath)

        $this.Configurations.PesterConfigurations.Run.Path = $ScriptPath
    }

    [void] BeforeAllTestsSetup() {
        $this.ClearFolder($this.Configurations.DotQlogicaeCLIFolderPath)
    }

    [void] AfterAllTestsSetup() {
        $this.ClearFolder($this.Configurations.DotQlogicaeCLIFolderPath)
    }

    [void] ClearFolder([string]$Path) {
        if ([string]::IsNullOrEmpty($Path)) { return }
        Get-ChildItem -Path $Path -Recurse -Force | Remove-Item -Recurse -Force
    }

    [void] CreateFolderTree([string]$Path) {
        if ([string]::IsNullOrEmpty($Path)) {
            return
        }

        if (-not (Test-Path $Path)) {
            New-Item -Path $Path -ItemType Directory -Force | Out-Null
        }
    }

    [void] ConsoleLog([string]$Text) {
        if ([string]::IsNullOrEmpty($Text)) {
            return
        }

        if ($this.Configurations.IsConsoleLoggingEnabled) {
            Write-Information $Text
        }
    }

    [void] ConsoleLog([string]$Text, [bool]$IsConsoleLoggingEnabled = $true) {
        if ([string]::IsNullOrEmpty($Text)) {
            return
        }

        if ($IsConsoleLoggingEnabled) {
            Write-Information $Text
        }
    }

    [int] GetLineCount([string]$Text) {
        return ($Text -split "`r?`n" | Where-Object { $_.Trim() -ne "" }).Count
    }

    [int] GetStringLength([string]$Text) {
        if ([string]::IsNullOrEmpty($Text)) {
            return 0
        }

        return $Text.Length
    }

    [int] GetPatternMatchCount([string]$Text, [string]$Pattern) {
        return ([regex]::Matches($Text, $Pattern, 'IgnoreCase')).Count
    }

    [int] GetPatternMatchCount([string]$Text, [string]$Pattern, [string]$CaseSensitivity = 'IgnoreCase') {
        return ([regex]::Matches($Text, $Pattern, $CaseSensitivity)).Count
    }

    [int] GetUUIDv4Count([string]$Text) {
        return ([regex]::Matches($Text, $this.Configurations.UUID4Pattern, 'IgnoreCase')).Count
    }
}

$script:QlogicaeKmandInstance = [QLogicaeKmand]::GetInstance()
