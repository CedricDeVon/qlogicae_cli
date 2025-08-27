
Describe "'qlogicae_cli uuid4' test suite" {
    BeforeAll {
        . $PSScriptRoot/qlogicae/configurations/imports.ps1

        $UUID4GenerateOutputFile = ".qlogicae/cli/uuid4-generate.txt"

        if (Test-Path $UUID4GenerateOutputFile) {
            Remove-Item $UUID4GenerateOutputFile
        }
    }

    AfterAll {
        if (Test-Path $UUID4GenerateOutputFile) {
            Remove-Item $UUID4GenerateOutputFile
        }
    }

    It "'qlogicae_cli uuid4' test: should be null or empty" {
        $TestResult = qlogicae_cli uuid4 | Out-String        

        $TestResult | Should -BeNullOrEmpty
    }

    It "'qlogicae_cli uuid4 --help' test: should not be null or empty" {
        $TestResult = qlogicae_cli uuid4 --help | Out-String
        Log -Text $TestResult

        $TestResult | Should -Not -BeNullOrEmpty
    }
    
    It "'qlogicae_cli uuid4 generate --count='-10' test: should terminate" {
        $TestResult = qlogicae_cli uuid4 generate --count='-10' | Out-String
        
        $TestResult | Should -BeNullOrEmpty
    }

    It "'qlogicae_cli uuid4 generate --count='-1' test: should terminate" {
        $TestResult = qlogicae_cli uuid4 generate --count='-1' | Out-String
        
        $TestResult | Should -BeNullOrEmpty
    }

    It "'qlogicae_cli uuid4 generate --count='0' test: should terminate" {
        $TestResult = qlogicae_cli uuid4 generate --count='0' | Out-String
        
        $TestResult | Should -BeNullOrEmpty
    }

    It "'qlogicae_cli uuid4 generate test: should generate 1 uuid4(s) on the console" {
        $TestResult = qlogicae_cli uuid4 generate | Out-String
        Log -Text $TestResult

        $TestResult | Should -Not -BeNullOrEmpty
    }

    It "'qlogicae_cli uuid4 generate --count='10' test: should generate 10 uuid4(s) on the console" {
        $TestResult = qlogicae_cli uuid4 generate --count='10' | Out-String
        Log -Text $TestResult

        $TestResult | Should -Not -BeNullOrEmpty
    }

    It "'qlogicae_cli uuid4 generate --count='10' --is-file-output-enabled='false'' test: should generate 10 uuid4(s) on the console but not the file" {
        $TestResult = qlogicae_cli uuid4 generate --count='10' --is-file-output-enabled='false' | Out-String
        Log -Text $TestResult

        $TestResult | Should -Not -BeNullOrEmpty
    }

    It "'qlogicae_cli uuid4 generate --count='10' --is-file-output-enabled='true'' test: should generate 10 uuid4(s) on the console and file" {
        $TestResult = qlogicae_cli uuid4 generate --count='10' --is-file-output-enabled='true' | Out-String
        Log -Text $TestResult

        $TestResult | Should -Not -BeNullOrEmpty
        Test-Path $UUID4GenerateOutputFile | Should -BeTrue
    }

    It "'qlogicae_cli uuid4 generate --count='10' --is-verbose-logging-enabled='false' test: should generate 10 uuid4(s) on the console" {
        $TestResult = qlogicae_cli uuid4 generate --count='10' --is-verbose-logging-enabled='false' | Out-String
        Log -Text $TestResult

        $TestResult | Should -Not -BeNullOrEmpty
    }

    It "'qlogicae_cli uuid4 generate --count='10' --is-verbose-logging-enabled='true' test: should generate 10 uuid4(s) on the console" {
        $TestResult = qlogicae_cli uuid4 generate --count='10' --is-verbose-logging-enabled='true' | Out-String
        Log -Text $TestResult

        $TestResult | Should -Not -BeNullOrEmpty
    }
}
