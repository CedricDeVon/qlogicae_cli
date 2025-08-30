
class QLogicaeKmand {
    hidden static [QLogicaeKmand]$Instance
    [PSCustomObject]$Configurations

    hidden QLogicaeKmand() {
        $RootFolderPath = (Get-Location).Path
        $ParentFolderPath = Split-Path -Path (Get-Location) -Parent

        Write-Host $ParentFolderPath

        $this.Configurations = [PSCustomObject]@{
            IsConsoleLoggingEnabled = $true
            IsFileLoggingEnabled    = $true

            UUID4Pattern = "[0-9a-f]{8}-[0-9a-f]{4}-4[0-9a-f]{3}-[89ab][0-9a-f]{3}-[0-9a-f]{12}"

            RootFolderPath = $RootFolderPath
            ParentFolderPath = $ParentFolderPath

            DotQLogicaeFolderPath = "$RootFolderPath/.qlogicae"
            DotQLogicaeCLIFolderPath = "$RootFolderPath/.qlogicae/cli"
            DotQLogicaeLogsFolderPath = "$RootFolderPath/.qlogicae/kmand/pester/logs"
            DotQLogicaeLogsPesterFolderPath = "$RootFolderPath/.qlogicae/kmand/pester/logs"
            DotQLogicaeKmandEnvironmentFolderPath = "$RootFolderPath/.qlogicae/kmand/environment"
            QLogicaeTemplatesVS2022ApplicationFolderPath = "$ParentFolderPath/qlogicae_cli/qlogicae/templates/vs2022/application"

            QLogicaePrivateFilePath = "$RootFolderPath/qlogicae.private.json"
            DotQLogicaeCLICustomOutputFilePath = "$RootFolderPath/.qlogicae/cli/custom_output.txt"
            DotQLogicaeCLIDefaultOutputFilePath = "$RootFolderPath/.qlogicae/cli/default_output.txt"
            DotQLogicaeLogsPesterJUnitFile = "$RootFolderPath/.qlogicae/kmand/pester/logs/junit.xml"          
            DotQLogicaeLogsPesterConsoleFile = "$RootFolderPath/.qlogicae/kmand/pester/logs/console.txt"
            QLogicaeConfigurationsPublicFilePath = "$RootFolderPath/qlogicae/configurations/qlogicae.public.json"
            
            RelativeQLogicaePrivateFilePath = "qlogicae.private.json"
            RelativeQLogicaeConfigurationsPublicFilePath = "qlogicae/configurations/qlogicae.public.json"
            
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
                    OutputPath = "$RootFolderPath/.qlogicae/kmand/pester/logs/coverage.xml"
                }
                Debug = @{
                    ShowFullErrors = $true
                    WriteDebugMessages = $true
                }
                TestResult = @{
                    Enabled = $true
                    OutputPath = "$RootFolderPath/.qlogicae/kmand/pester/logs/nunit.xml"
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
        $this.CreateFolderTree($this.Configurations.DotQLogicaeFolderPath)
        $this.CreateFolderTree($this.Configurations.DotQLogicaeCLIFolderPath)
        $this.CreateFolderTree($this.Configurations.DotQLogicaeLogsFolderPath)
        $this.CreateFolderTree($this.Configurations.DotQLogicaeLogsPesterFolderPath)
        $this.CreateFolderTree($this.Configurations.DotQLogicaeKmandEnvironmentFolderPath)

        $this.Configurations.PesterConfigurations.Run.Path = $ScriptPath
    }

    [void] BeforeAllTestsSetup() {
        $this.ClearFolder($this.Configurations.DotQLogicaeCLIFolderPath)
        $this.ClearFolder($this.Configurations.DotQLogicaeKmandEnvironmentFolderPath)

        cd $this.Configurations.DotQLogicaeKmandEnvironmentFolderPath
    }

    [void] AfterAllTestsSetup() {
        cd $this.Configurations.RootFolderPath

        $this.ClearFolder($this.Configurations.DotQLogicaeCLIFolderPath)
        $this.ClearFolder($this.Configurations.DotQLogicaeKmandEnvironmentFolderPath)
    }

    [void] ClearFolder([string]$Path) {
        if ([string]::IsNullOrEmpty($Path)) {
            return
        }
        
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

    [boolean] IsFolderEmpty([string]$Path) {
        if (-not (Test-Path $Path -PathType Container)) {
            return $false
        }

        return -Not (Get-ChildItem -Path $Path -Force -Recurse)
    }
}

$script:QlogicaeKmandInstance = [QLogicaeKmand]::GetInstance()
