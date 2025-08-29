
Describe "[qlogicae_cli argon2id] test suite" {
    BeforeAll {
        . $PSScriptRoot/imports.ps1

        $QLogicaeKmandInstance.BeforeAllTestsSetup()
    }

    AfterAll {
        $QLogicaeKmandInstance.AfterAllTestsSetup()
    }

    Context "[qlogicae_cli argon2id] test cases" {
        It "[qlogicae_cli argon2id]: should terminate" {
            $TestResult = qlogicae_cli argon2id | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id --help]: should not be null or empty" {
            $TestResult = qlogicae_cli argon2id --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context "[qlogicae_cli argon2id hash] test cases" {
        It "[qlogicae_cli argon2id hash]: should terminate" {
            $TestResult = qlogicae_cli argon2id hash | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id hash --help]: should not be null or empty" {
            $TestResult = qlogicae_cli argon2id hash --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context "[qlogicae_cli argon2id hash --text] test cases" {
        It "[qlogicae_cli argon2id hash --text='']: should terminate" {
            $TestResult = qlogicae_cli argon2id hash --text='' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id hash --text='a']: should generate an argon2id hash" {
            $TestResult = qlogicae_cli argon2id hash --text='a' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "argon2id")) | Should -Be 1
        }

        It "[qlogicae_cli argon2id hash --text='@Password_1234']: should generate an argon2id hash" {
            $TestResult = qlogicae_cli argon2id hash --text='@Password_1234' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "argon2id")) | Should -Be 1
        }
    }

    Context "[qlogicae_cli argon2id hash --text --is-file-output-enabled] test cases" {
        It "[qlogicae_cli argon2id hash --text='@Password_1234' --is-file-output-enabled='']: terminate" {
            $TestResult = qlogicae_cli argon2id hash --text='@Password_1234' --is-file-output-enabled='' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id hash --text='@Password_1234' --is-file-output-enabled='false']: should generate an argon2id hash" {
            $TestResult = qlogicae_cli argon2id hash --text='@Password_1234' --is-file-output-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "argon2id")) | Should -Be 1
            Test-Path ".qlogicae/cli/argon2id-hash.txt" | Should -BeFalse
        }

        It "[qlogicae_cli argon2id hash --text='@Password_1234' --is-file-output-enabled='true']: should generate an argon2id hash" {
            $TestResult = qlogicae_cli argon2id hash --text='@Password_1234' --is-file-output-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "argon2id")) | Should -Be 1
            Test-Path ".qlogicae/cli/argon2id-hash.txt" | Should -BeTrue
        }
    }

    Context "[qlogicae_cli argon2id hash --text --is-file-output-enabled --output-file-path] test cases" {
        It "[qlogicae_cli argon2id hash --text='@Password_1234' --is-file-output-enabled='true' --output-file-path='']: terminate" {
            $TestResult = qlogicae_cli argon2id hash --text='@Password_1234' --is-file-output-enabled='true' --output-file-path='' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id hash --text='@Password_1234' --is-file-output-enabled='true' --output-file-path='.qlogicae/cli/custom_output.txt']: should generate an argon2id hash" {
            $TestResult = qlogicae_cli argon2id hash --text='@Password_1234' --is-file-output-enabled='true' --output-file-path='.qlogicae/cli/custom_output.txt' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "argon2id")) | Should -Be 1
            Test-Path ".qlogicae/cli/custom_output.txt" | Should -BeTrue
        }
    }
    
    Context "[qlogicae_cli argon2id hash --text --is-verbose-logging-enabled] test cases" {
        It "[qlogicae_cli argon2id hash --text='@Password_1234' --is-verbose-logging-enabled='']: should terminate" {
            $TestResult = qlogicae_cli argon2id hash --text='@Password_1234' --is-verbose-logging-enabled='' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id hash --text='@Password_1234' --is-verbose-logging-enabled='false']: should generate an argon2id hash" {
            $TestResult = qlogicae_cli argon2id hash --text='@Password_1234' --is-verbose-logging-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "argon2id")) | Should -Be 1
        }

        It "[qlogicae_cli argon2id hash --text='@Password_1234' --is-verbose-logging-enabled='true']: should generate an argon2id hash" {
            $TestResult = qlogicae_cli argon2id hash --text='@Password_1234' --is-verbose-logging-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -BeGreaterOrEqual 1
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "argon2id")) | Should -Be 1
        }
    }

    Context "[qlogicae_cli argon2id verify] test cases" {
        It "[qlogicae_cli argon2id verify]: should terminate" {
            $TestResult = qlogicae_cli argon2id verify | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id verify --help]: should not be null or empty" {
            $TestResult = qlogicae_cli argon2id verify --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }
    
    Context "[qlogicae_cli argon2id verify --hash --key] test cases" {
        It "[qlogicae_cli argon2id verify --hash='']: should terminate" {
            $TestResult = qlogicae_cli argon2id verify --hash='' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id verify --key='']: should terminate" {
            $TestResult = qlogicae_cli argon2id verify --key='' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }
    
        It "[qlogicae_cli argon2id verify --hash='' --key='']: should terminate" {
            $TestResult = qlogicae_cli argon2id verify --hash='' --key='' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id verify --key='@Password_1234' --hash='']: should terminate" {
            $TestResult = qlogicae_cli argon2id verify --key='@Password_1234' --hash='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id verify --hash='$argon2id$v=19$m=65536,t=3,p=2$fMWT7AlyfqZ5BwsUcAU/+A$cJZ3S6DSFAt1AP2VRX64OTtWUu+WqUQ3wkAEifcGr7k' --key='']: should terminate" {
            $TestResult = qlogicae_cli argon2id verify --hash='$argon2id$v=19$m=65536,t=3,p=2$fMWT7AlyfqZ5BwsUcAU/+A$cJZ3S6DSFAt1AP2VRX64OTtWUu+WqUQ3wkAEifcGr7k' --key='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }
        
        It "[qlogicae_cli argon2id verify --hash='a' --key='@Password_1234']: should return 'false'" {
            $TestResult = qlogicae_cli argon2id verify --hash='a' --key='@Password_1234' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "false")) | Should -Be 1
        }

        It "[qlogicae_cli argon2id verify --hash='$argon2id$v=19$m=65536,t=3,p=2$fMWT7AlyfqZ5BwsUcAU/+A$cJZ3S6DSFAt1AP2VRX64OTtWUu+WqUQ3wkAEifcGr7k' --key='a']: should return 'false'" {
            $TestResult = qlogicae_cli argon2id verify --hash='$argon2id$v=19$m=65536,t=3,p=2$fMWT7AlyfqZ5BwsUcAU/+A$cJZ3S6DSFAt1AP2VRX64OTtWUu+WqUQ3wkAEifcGr7k' --key='a' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "false")) | Should -Be 1
        }

        It "[qlogicae_cli argon2id verify --hash='$argon2id$v=19$m=65536,t=3,p=2$fMWT7AlyfqZ5BwsUcAU/+A$cJZ3S6DSFAt1AP2VRX64OTtWUu+WqUQ3wkAEifcGr7k' --key='@Password_1234']: should return 'true'" {
            $TestResult = qlogicae_cli argon2id verify --hash='$argon2id$v=19$m=65536,t=3,p=2$fMWT7AlyfqZ5BwsUcAU/+A$cJZ3S6DSFAt1AP2VRX64OTtWUu+WqUQ3wkAEifcGr7k' --key='@Password_1234' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "true")) | Should -Be 1
        }
    }

    Context "[qlogicae_cli argon2id verify --hash --key --is-verbose-logging-enabled] test cases" {  
        It "[qlogicae_cli argon2id verify --hash='$argon2id$v=19$m=65536,t=3,p=2$fMWT7AlyfqZ5BwsUcAU/+A$cJZ3S6DSFAt1AP2VRX64OTtWUu+WqUQ3wkAEifcGr7k' --key='@Password_1234' --is-verbose-logging-enabled='']: should terminate" {
            $TestResult = qlogicae_cli argon2id verify --hash='$argon2id$v=19$m=65536,t=3,p=2$fMWT7AlyfqZ5BwsUcAU/+A$cJZ3S6DSFAt1AP2VRX64OTtWUu+WqUQ3wkAEifcGr7k' --key='@Password_1234' --is-verbose-logging-enabled='' | Out-String
        
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id verify --hash='$argon2id$v=19$m=65536,t=3,p=2$fMWT7AlyfqZ5BwsUcAU/+A$cJZ3S6DSFAt1AP2VRX64OTtWUu+WqUQ3wkAEifcGr7k' --key='@Password_1234' --is-verbose-logging-enabled='false']: should return 'false'" {
            $TestResult = qlogicae_cli argon2id verify --hash='$argon2id$v=19$m=65536,t=3,p=2$fMWT7AlyfqZ5BwsUcAU/+A$cJZ3S6DSFAt1AP2VRX64OTtWUu+WqUQ3wkAEifcGr7k' --key='@Password_1234' --is-verbose-logging-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "true")) | Should -Be 1
        }

        It "[qlogicae_cli argon2id verify --hash='$argon2id$v=19$m=65536,t=3,p=2$fMWT7AlyfqZ5BwsUcAU/+A$cJZ3S6DSFAt1AP2VRX64OTtWUu+WqUQ3wkAEifcGr7k' --key='@Password_1234' --is-verbose-logging-enabled='true']: should return 'true'" {
            $TestResult = qlogicae_cli argon2id verify --hash='$argon2id$v=19$m=65536,t=3,p=2$fMWT7AlyfqZ5BwsUcAU/+A$cJZ3S6DSFAt1AP2VRX64OTtWUu+WqUQ3wkAEifcGr7k' --key='@Password_1234' --is-verbose-logging-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -BeGreaterOrEqual 1
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "true")) | Should -Be 1
        }
    }
}
