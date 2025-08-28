
Describe "[qlogicae_cli uuid4] test suite" {
    BeforeAll {
        . $PSScriptRoot/imports.ps1

        $QLogicaeKmandInstance.BeforeAllTestsSetup()
    }

    AfterAll {
        $QLogicaeKmandInstance.AfterAllTestsSetup()
    }

    Context ("[qlogicae_cli uuid4] test cases") {
        It ("[qlogicae_cli uuid4]: should terminate") {
            $TestResult = qlogicae_cli uuid4 | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It ("[qlogicae_cli uuid4 --help]: should not be null or empty") {
            $TestResult = qlogicae_cli uuid4 --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli uuid4 generate (defaults)] test cases") {
        It ("[qlogicae_cli uuid4 generate]: generate instance(s) based on default parameters") {
            $TestResult = qlogicae_cli uuid4 generate | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetUUIDv4Count($TestResult)) | Should -Be 1
            $TestResult | Should -Not -BeNullOrEmpty
        }

        It ("[qlogicae_cli uuid4 generate --help]: should not be null or empty") {
            $TestResult = qlogicae_cli uuid4 generate --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli uuid4 generate --count] test cases") {
        It ("[qlogicae_cli uuid4 generate --count='']: should terminate") {
            $TestResult = qlogicae_cli uuid4 generate --count='' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It ("[qlogicae_cli uuid4 generate --count='-10']: should terminate") {
            $TestResult = qlogicae_cli uuid4 generate --count='-10' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It ("[qlogicae_cli uuid4 generate --count='-1']: should terminate") {
            $TestResult = qlogicae_cli uuid4 generate --count='-1' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It ("[qlogicae_cli uuid4 generate --count='0']: should terminate") {
            $TestResult = qlogicae_cli uuid4 generate --count='0' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It ("[qlogicae_cli uuid4 generate --count='1']: should generate 1 instance(s) on the console") {
            $TestResult = qlogicae_cli uuid4 generate --count='1' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetUUIDv4Count($TestResult)) | Should -Be 1
            $TestResult | Should -Not -BeNullOrEmpty
        }

        It ("[qlogicae_cli uuid4 generate --count='10']: should generate 10 instance(s) on the console") {
            $TestResult = qlogicae_cli uuid4 generate --count='10' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 10
            ($QLogicaeKmandInstance.GetUUIDv4Count($TestResult)) | Should -Be 10
            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli uuid4 generate --is-file-output-enabled] test cases") {
        It ("[qlogicae_cli uuid4 generate --is-file-output-enabled='']: should terminate") {
            $TestResult = qlogicae_cli uuid4 generate --is-file-output-enabled='' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It ("[qlogicae_cli uuid4 generate --is-file-output-enabled='false']: should generate 1 instance(s) on the console but not the file") {
            $TestResult = qlogicae_cli uuid4 generate --is-file-output-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetUUIDv4Count($TestResult)) | Should -Be 1
            $TestResult | Should -Not -BeNullOrEmpty
        }

        It ("[qlogicae_cli uuid4 generate --is-file-output-enabled='true']: should generate 1 instance(s) on the console and file") {
            $TestResult = qlogicae_cli uuid4 generate --is-file-output-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetUUIDv4Count($TestResult)) | Should -Be 1
            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli uuid4 generate --is-verbose-logging-enabled] test cases") {
        It ("[qlogicae_cli uuid4 generate --is-verbose-logging-enabled='']: should terminate") {
            $TestResult = qlogicae_cli uuid4 generate --is-verbose-logging-enabled='' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It ("[qlogicae_cli uuid4 generate --is-verbose-logging-enabled='false']: should generate 1 instance(s) on the console") {
            $TestResult = qlogicae_cli uuid4 generate --is-verbose-logging-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetUUIDv4Count($TestResult)) | Should -Be 1
            $TestResult | Should -Not -BeNullOrEmpty
        }

        It ("[qlogicae_cli uuid4 generate --is-verbose-logging-enabled='true']: should generate 1 instance(s) on the console") {
            $TestResult = qlogicae_cli uuid4 generate --is-verbose-logging-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 3
            ($QLogicaeKmandInstance.GetUUIDv4Count($TestResult)) | Should -Be 1
            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli uuid4 generate --output-file-path] test cases") {
        It ("[qlogicae_cli uuid4 generate --is-file-output-enabled='true' --output-file-path='']: should terminate") {
            $TestResult = qlogicae_cli uuid4 generate --is-file-output-enabled='true' --output-file-path='' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It ("[qlogicae_cli uuid4 generate --is-file-output-enabled='false' --output-file-path='.qlogicae/cli/custom_output.txt']: should generate 1 instance(s) on the console and custom file") {
            $TestResult = qlogicae_cli uuid4 generate --is-file-output-enabled='false' --output-file-path="$($QLogicaeKmandInstance.Configurations.DotQLogicaeCLICustomOutputFilePath)" | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetUUIDv4Count($TestResult)) | Should -Be 1
            $TestResult | Should -Not -BeNullOrEmpty
            Test-Path "$($QLogicaeKmandInstance.Configurations.DotQLogicaeCLICustomOutputFilePath)" | Should -BeFalse
        }

        It ("[qlogicae_cli uuid4 generate --is-file-output-enabled='true']: should generate 1 instance(s) on the console and default file") {
            $TestResult = qlogicae_cli uuid4 generate --is-file-output-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetUUIDv4Count($TestResult)) | Should -Be 1
            $TestResult | Should -Not -BeNullOrEmpty
            Test-Path ".qlogicae/cli/uuid4-generate.txt" | Should -BeTrue
        }

        It ("[qlogicae_cli uuid4 generate --is-file-output-enabled='true' --output-file-path='.qlogicae/cli/custom_output.txt']: should generate 1 instance(s) on the console and custom file") {
            $TestResult = qlogicae_cli uuid4 generate --is-file-output-enabled='true' --output-file-path="$($QLogicaeKmandInstance.Configurations.DotQLogicaeCLICustomOutputFilePath)" | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)
            
            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetUUIDv4Count($TestResult)) | Should -Be 1
            $TestResult | Should -Not -BeNullOrEmpty
            Test-Path "$($QLogicaeKmandInstance.Configurations.DotQLogicaeCLICustomOutputFilePath)" | Should -BeTrue
        }
    }
}
