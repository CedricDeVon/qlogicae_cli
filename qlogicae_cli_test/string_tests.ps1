
Describe "[qlogicae_cli string] test suite" {
    BeforeAll {
        . $PSScriptRoot/imports.ps1

        $QLogicaeKmandInstance.BeforeAllTestsSetup()
    }

    AfterAll {
        $QLogicaeKmandInstance.AfterAllTestsSetup()
    }

    Context ("[qlogicae_cli string] test cases") {
        It "[qlogicae_cli string]: should terminate" {
            $TestResult = qlogicae_cli string | Out-String        

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli string --help]: should not be null or empty" {
            $TestResult = qlogicae_cli string --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli string generate] test cases") {
        It "[qlogicae_cli string generate]: generate instance(s) based on default parameters" {
            $TestResult = qlogicae_cli string generate | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetStringLength($TestResult)) | Should -BeGreaterOrEqual 10
            $TestResult | Should -Not -BeNullOrEmpty
        }

        It "[qlogicae_cli string generate --help]: should not be null or empty" {
            $TestResult = qlogicae_cli string generate --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli string generate --length] test cases") {
        It "[qlogicae_cli string generate --length='']: should terminate" {
            $TestResult = qlogicae_cli string generate --length='' | Out-String
        
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli string generate --length='-10']: should terminate" {
            $TestResult = qlogicae_cli string generate --length='-10' | Out-String
        
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli string generate --length='-1']: should terminate" {
            $TestResult = qlogicae_cli string generate --length='-1' | Out-String
        
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli string generate --length='0']: should terminate" {
            $TestResult = qlogicae_cli string generate --length='0' | Out-String
        
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli string generate --length='1']: should contain 1 characters" {
            $TestResult = qlogicae_cli string generate --length='1' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetStringLength($TestResult)) | Should -BeGreaterOrEqual 1
            $TestResult | Should -Not -BeNullOrEmpty
        }

        It "[qlogicae_cli string generate --length='10']: should contain 10 characters" {
            $TestResult = qlogicae_cli string generate --length='10' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetStringLength($TestResult)) | Should -BeGreaterOrEqual 10
            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli string generate --count] test cases") {
        It "[qlogicae_cli string generate --count='']: should terminate" {
            $TestResult = qlogicae_cli string generate --count='' | Out-String
        
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli string generate --count='-10']: should terminate" {
            $TestResult = qlogicae_cli string generate --count='-10' | Out-String
        
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli string generate --count='-1']: should terminate" {
            $TestResult = qlogicae_cli string generate --count='-1' | Out-String
        
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli string generate --count='0']: should terminate" {
            $TestResult = qlogicae_cli string generate --count='0' | Out-String
        
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli string generate --count='1']: should generate 10 instance(s)" {
            $TestResult = qlogicae_cli string generate --count='1' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            $TestResult | Should -Not -BeNullOrEmpty
        }

        It "[qlogicae_cli string generate --count='10']: should generate 10 instance(s)" {
            $TestResult = qlogicae_cli string generate --count='10' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 10
            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli string generate --character-set] test cases") {
        It "[qlogicae_cli string generate --character-set='']: should terminate" {
            $TestResult = qlogicae_cli string generate --character-set='' | Out-String
        
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli string generate --character-set='a']: should generate 1 instance(s) with character(s) 'a'" {
            $TestResult = qlogicae_cli string generate --character-set='a' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "[a]")) | Should -BeGreaterOrEqual 1
            $TestResult | Should -Not -BeNullOrEmpty
        }

        It "[qlogicae_cli string generate --character-set='ab']: should generate 1 instance(s) with character(s) 'ab'" {
            $TestResult = qlogicae_cli string generate --character-set='ab' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "[ab]")) | Should -BeGreaterOrEqual 1
            $TestResult | Should -Not -BeNullOrEmpty
        }

        It "[qlogicae_cli string generate --character-set='aba']: should generate 1 instance(s) with character(s) 'aaaaabaaaaa'" {
            $TestResult = qlogicae_cli string generate --character-set='aaaaabaaaaa' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "[ab]")) | Should -BeGreaterOrEqual 1
            $TestResult | Should -Not -BeNullOrEmpty
        }

        It "[qlogicae_cli string generate --character-set='0123456789ABCDEF']: should generate 1 instance(s) with character(s) '0123456789ABCDEF'" {
            $TestResult = qlogicae_cli string generate --character-set='0123456789ABCDEF' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "[0123456789ABCDEF]")) | Should -BeGreaterOrEqual 1
            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli string generate --is-verbose-logging-enabled] test cases") {
        It "[qlogicae_cli string generate --is-verbose-logging-enabled='']: should terminate" {
            $TestResult = qlogicae_cli string generate --is-verbose-logging-enabled='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }
    
        It "[qlogicae_cli string generate --is-verbose-logging-enabled='false']: should generate 1 instance(s)" {
            $TestResult = qlogicae_cli string generate --is-verbose-logging-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            $TestResult | Should -Not -BeNullOrEmpty
        }

        It "[qlogicae_cli string generate --is-verbose-logging-enabled='true']: should generate 1 instance(s)" {
            $TestResult = qlogicae_cli string generate --is-verbose-logging-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 3
            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli string generate --is-file-output-enabled] test cases") {
        It "[qlogicae_cli string generate --is-file-output-enabled='']: should terminate" {
            $TestResult = qlogicae_cli string generate --is-file-output-enabled='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }    
    
        It "[qlogicae_cli string generate --is-file-output-enabled='false']: should should generate 1 instance(s) on the console but not the file" {
            $TestResult = qlogicae_cli string generate --is-file-output-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }

        It "[qlogicae_cli string generate --is-file-output-enabled='true']: should generate 1 instance(s) on the console and file" {
            $TestResult = qlogicae_cli string generate --is-file-output-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            Test-Path ".qlogicae/cli/string-generate.txt" | Should -BeTrue
        }        
    }

    Context ("[qlogicae_cli string generate --is-file-output-enabled --output-file-path] test cases") {
        It "[qlogicae_cli string generate --is-file-output-enabled='true' --output-file-path='']: should terminate" {
            $TestResult = qlogicae_cli string generate --is-file-output-enabled='true' --output-file-path='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }    
    
        It "[qlogicae_cli string generate --is-file-output-enabled='true' --output-file-path='.qlogicae/cli/custom_output.txt']: should generate 1 instance(s) on the console and file" {
            $TestResult = qlogicae_cli string generate --is-file-output-enabled='true' --output-file-path="$($QLogicaeKmandInstance.Configurations.DotQlogicaeCLICustomOutputFilePath)" | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            Test-Path "$($QLogicaeKmandInstance.Configurations.DotQlogicaeCLICustomOutputFilePath)" | Should -BeTrue
        }        
    }
}
