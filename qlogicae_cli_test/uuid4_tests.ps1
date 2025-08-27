
Describe "[qlogicae_cli uuid4] test suite" {
    BeforeAll {
        . $PSScriptRoot/imports.ps1

        $defaultOutputFile = ".qlogicae/cli/uuid4-generate.txt"

        QLogicaePesterTest_BeforeAllTestsSetup
    }

    AfterAll {
        QLogicaePesterTest_AfterAllTestsSetup
    }

    Context ("[qlogicae_cli uuid4] test cases") {
        It ("[qlogicae_cli uuid4]: terminate") {
            $testResult = qlogicae_cli uuid4 | Out-String        

            $testResult | Should -BeNullOrEmpty
        }

        It ("[qlogicae_cli uuid4 --help]: should not be null or empty") {
            $testResult = qlogicae_cli uuid4 --help | Out-String
            QLogicaePesterTest_ConsoleLog -Text $testResult

            $testResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli uuid4 generate (defaults)] test cases") {
        It ("[qlogicae_cli uuid4 generate]: generate instance(s) based on default parameters") {
            $testResult = qlogicae_cli uuid4 generate | Out-String
            QLogicaePesterTest_ConsoleLog -Text $testResult

            (QLogicaePesterTest_GetLineCount -Text $testResult) | Should -BeGreaterOrEqual 1
            (QLogicaePesterTest_GetUUIDv4Count -Text $testResult) | Should -Be 1
            $testResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli uuid4 generate --count] test cases") {
        It ("[qlogicae_cli uuid4 generate --count='']: should terminate") {
            $testResult = qlogicae_cli uuid4 generate --count='' | Out-String
        
            $testResult | Should -BeNullOrEmpty
        }

        It ("[qlogicae_cli uuid4 generate --count='-10']: should terminate") {
            $testResult = qlogicae_cli uuid4 generate --count='-10' | Out-String
        
            $testResult | Should -BeNullOrEmpty
        }

        It ("[qlogicae_cli uuid4 generate --count='-1']: should terminate") {
            $testResult = qlogicae_cli uuid4 generate --count='-1' | Out-String
        
            $testResult | Should -BeNullOrEmpty
        }

        It ("[qlogicae_cli uuid4 generate --count='0']: should terminate") {
            $testResult = qlogicae_cli uuid4 generate --count='0' | Out-String
        
            $testResult | Should -BeNullOrEmpty
        }

        It ("[qlogicae_cli uuid4 generate --count='1']: should generate 1 instance(s) on the console") {
            $testResult = qlogicae_cli uuid4 generate --count='1' | Out-String
            QLogicaePesterTest_ConsoleLog -Text $testResult

            (QLogicaePesterTest_GetLineCount -Text $testResult) | Should -BeGreaterOrEqual 1
            (QLogicaePesterTest_GetUUIDv4Count -Text $testResult) | Should -Be 1
            $testResult | Should -Not -BeNullOrEmpty
        }

        It ("[qlogicae_cli uuid4 generate --count='10']: should generate 10 instance(s) on the console") {
            $testResult = qlogicae_cli uuid4 generate --count='10' | Out-String
            QLogicaePesterTest_ConsoleLog -Text $testResult

            (QLogicaePesterTest_GetLineCount -Text $testResult) | Should -BeGreaterOrEqual 10
            (QLogicaePesterTest_GetUUIDv4Count -Text $testResult) | Should -Be 10
            $testResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli uuid4 generate --is-file-output-enabled] test cases") {
        It ("[qlogicae_cli uuid4 generate --is-file-output-enabled='']: should terminate") {
            $testResult = qlogicae_cli uuid4 generate --is-file-output-enabled='' | Out-String
        
            $testResult | Should -BeNullOrEmpty
        }

        It ("[qlogicae_cli uuid4 generate --is-file-output-enabled='false']: should generate 1 instance(s) on the console but not the file") {
            $testResult = qlogicae_cli uuid4 generate --is-file-output-enabled='false' | Out-String
            QLogicaePesterTest_ConsoleLog -Text $testResult

            (QLogicaePesterTest_GetLineCount -Text $testResult) | Should -BeGreaterOrEqual 1
            (QLogicaePesterTest_GetUUIDv4Count -Text $testResult) | Should -Be 1
            $testResult | Should -Not -BeNullOrEmpty
        }

        It ("[qlogicae_cli uuid4 generate --is-file-output-enabled='true']: should generate 1 instance(s) on the console and file") {
            $testResult = qlogicae_cli uuid4 generate --is-file-output-enabled='true' | Out-String
            QLogicaePesterTest_ConsoleLog -Text $testResult

            (QLogicaePesterTest_GetLineCount -Text $testResult) | Should -BeGreaterOrEqual 1
            (QLogicaePesterTest_GetUUIDv4Count -Text $testResult) | Should -Be 1
            $testResult | Should -Not -BeNullOrEmpty
        }        
    }

    Context ("[qlogicae_cli uuid4 generate --is-verbose-logging-enabled] test cases") {
        It ("[qlogicae_cli uuid4 generate --is-verbose-logging-enabled='']: should terminate") {
            $testResult = qlogicae_cli uuid4 generate --is-verbose-logging-enabled='' | Out-String
        
            $testResult | Should -BeNullOrEmpty
        }

        It ("[qlogicae_cli uuid4 generate --is-verbose-logging-enabled='false']: should generate 1 instance(s) on the console") {
            $testResult = qlogicae_cli uuid4 generate --is-verbose-logging-enabled='false' | Out-String
            QLogicaePesterTest_ConsoleLog -Text $testResult

            (QLogicaePesterTest_GetLineCount -Text $testResult) | Should -BeGreaterOrEqual 1
            (QLogicaePesterTest_GetUUIDv4Count -Text $testResult) | Should -Be 1
            $testResult | Should -Not -BeNullOrEmpty
        }

        It ("[qlogicae_cli uuid4 generate --is-verbose-logging-enabled='true']: should generate 1 instance(s) on the console") {
            $testResult = qlogicae_cli uuid4 generate --is-verbose-logging-enabled='true' | Out-String
            QLogicaePesterTest_ConsoleLog -Text $testResult

            (QLogicaePesterTest_GetLineCount -Text $testResult) | Should -BeGreaterOrEqual 1
            (QLogicaePesterTest_GetUUIDv4Count -Text $testResult) | Should -Be 1
            $testResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli uuid4 generate --output-file-path] test cases") {
        It ("[qlogicae_cli uuid4 generate --is-file-output-enabled='true' --output-file-path='']: should terminate") {
            $testResult = qlogicae_cli uuid4 generate --is-file-output-enabled='true' --output-file-path='' | Out-String
        
            $testResult | Should -BeNullOrEmpty
        }

        It ("[qlogicae_cli uuid4 generate --is-file-output-enabled='false' --output-file-path='.qlogicae/cli/custom_output.txt']: should generate 1 instance(s) on the console and custom file") {
            $testResult = qlogicae_cli uuid4 generate --is-file-output-enabled='false' --output-file-path=$global:QLogicaePesterTest_DotQLogicaeCLICustomOutputFilePath | Out-String
            QLogicaePesterTest_ConsoleLog -Text $testResult

            (QLogicaePesterTest_GetLineCount -Text $testResult) | Should -BeGreaterOrEqual 1
            (QLogicaePesterTest_GetUUIDv4Count -Text $testResult) | Should -Be 1
            $testResult | Should -Not -BeNullOrEmpty
            Test-Path $global:QLogicaePesterTest_DotQLogicaeCLICustomOutputFilePath | Should -BeFalse
        }

        It ("[qlogicae_cli uuid4 generate --is-file-output-enabled='true']: should generate 1 instance(s) on the console and default file") {
            $testResult = qlogicae_cli uuid4 generate --is-file-output-enabled='true' | Out-String
            QLogicaePesterTest_ConsoleLog -Text $testResult

            (QLogicaePesterTest_GetLineCount -Text $testResult) | Should -BeGreaterOrEqual 1
            (QLogicaePesterTest_GetUUIDv4Count -Text $testResult) | Should -Be 1
            $testResult | Should -Not -BeNullOrEmpty
            Test-Path $defaultOutputFile | Should -BeTrue
        }

        It ("[qlogicae_cli uuid4 generate --is-file-output-enabled='true' --output-file-path='.qlogicae/cli/custom_output.txt']: should generate 1 instance(s) on the console and custom file") {
            $testResult = qlogicae_cli uuid4 generate --is-file-output-enabled='true' --output-file-path=$global:QLogicaePesterTest_DotQLogicaeCLICustomOutputFilePath | Out-String
            QLogicaePesterTest_ConsoleLog -Text $testResult

            (QLogicaePesterTest_GetLineCount -Text $testResult) | Should -BeGreaterOrEqual 1
            (QLogicaePesterTest_GetUUIDv4Count -Text $testResult) | Should -Be 1
            $testResult | Should -Not -BeNullOrEmpty
            Test-Path $global:QLogicaePesterTest_DotQLogicaeCLICustomOutputFilePath | Should -BeTrue
        }
    }
}
