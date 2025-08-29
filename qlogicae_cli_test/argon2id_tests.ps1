
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
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "argon2id")) | Should -Be 1
        }

        It "[qlogicae_cli argon2id hash --text='$Password_1234']: should generate an argon2id hash" {
            $TestResult = qlogicae_cli argon2id hash --text='$Password_1234' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "argon2id")) | Should -Be 1
        }
    }

    Context "[qlogicae_cli argon2id hash --text --is-file-output-enabled] test cases" {
        It "[qlogicae_cli argon2id hash --text='$Password_1234' --is-file-output-enabled='']: terminate" {
            $TestResult = qlogicae_cli argon2id hash --text='$Password_1234' --is-file-output-enabled='' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id hash --text='$Password_1234' --is-file-output-enabled='false']: should generate an argon2id hash" {
            $TestResult = qlogicae_cli argon2id hash --text='$Password_1234' --is-file-output-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "argon2id")) | Should -Be 1
        }

        It "[qlogicae_cli argon2id hash --text='$Password_1234' --is-file-output-enabled='true']: should generate an argon2id hash" {
            $TestResult = qlogicae_cli argon2id hash --text='$Password_1234' --is-file-output-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "argon2id")) | Should -Be 1
        }
    }
    
    Context "[qlogicae_cli argon2id hash --text --is-verbose-logging-enabled] test cases" {
        It "[qlogicae_cli argon2id hash --text='$Password_1234' --is-verbose-logging-enabled='']: should terminate" {
            $TestResult = qlogicae_cli argon2id hash --text='$Password_1234' --is-verbose-logging-enabled='' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id hash --text='$Password_1234' --is-verbose-logging-enabled='false']: should generate an argon2id hash" {
            $TestResult = qlogicae_cli argon2id hash --text='$Password_1234' --is-verbose-logging-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "argon2id")) | Should -Be 1
        }

        It "[qlogicae_cli argon2id hash --text='$Password_1234' --is-verbose-logging-enabled='true']: should generate an argon2id hash" {
            $TestResult = qlogicae_cli argon2id hash --text='$Password_1234' --is-verbose-logging-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
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
        It "[qlogicae_cli argon2id verify --hash='' --key='']: should terminate" {
            $TestResult = qlogicae_cli argon2id verify --hash='' --key='' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id verify --hash='' --key='$Password_1234']: should terminate" {
            $TestResult = qlogicae_cli argon2id verify --hash='' --key='$Password_1234' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id verify --hash='$argon2id$v=19$m=65536,t=3,p=2$KfOoUD89/AQhRxbwcqxUGQ$+zS4EUYI7cxOTWhA6NfdOk4i0H+GeAH/M+Ce9Jt8eag' --key='']: should terminate" {
            $TestResult = qlogicae_cli argon2id verify --hash='$argon2id$v=19$m=65536,t=3,p=2$KfOoUD89/AQhRxbwcqxUGQ$+zS4EUYI7cxOTWhA6NfdOk4i0H+GeAH/M+Ce9Jt8eag' --key='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }
        
        It "[qlogicae_cli argon2id verify --hash='a' --key='$Password_1234']: should return false" {
            $TestResult = qlogicae_cli argon2id verify --hash='a' --key='$Password_1234' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "false")) | Should -Be 1
        }

        It "[qlogicae_cli argon2id verify --hash='$argon2id$v=19$m=65536,t=3,p=2$KfOoUD89/AQhRxbwcqxUGQ$+zS4EUYI7cxOTWhA6NfdOk4i0H+GeAH/M+Ce9Jt8eag' --key='a']: should return false" {
            $TestResult = qlogicae_cli argon2id verify --hash='$argon2id$v=19$m=65536,t=3,p=2$KfOoUD89/AQhRxbwcqxUGQ$+zS4EUYI7cxOTWhA6NfdOk4i0H+GeAH/M+Ce9Jt8eag' --key='a' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "false")) | Should -Be 1
        }

        It "[qlogicae_cli argon2id verify --hash='$argon2id$v=19$m=65536,t=3,p=2$KfOoUD89/AQhRxbwcqxUGQ$+zS4EUYI7cxOTWhA6NfdOk4i0H+GeAH/M+Ce9Jt8eag' --key='$Password_1234']: should return true" {
            $TestResult = qlogicae_cli argon2id verify --hash='$argon2id$v=19$m=65536,t=3,p=2$KfOoUD89/AQhRxbwcqxUGQ$+zS4EUYI7cxOTWhA6NfdOk4i0H+GeAH/M+Ce9Jt8eag' --key='$Password_1234' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "true")) | Should -Be 1
        }
    }

    Context "[qlogicae_cli argon2id verify --hash --key --is-verbose-logging-enabled] test cases" {  
        It "[qlogicae_cli argon2id verify --hash='$argon2id$v=19$m=65536,t=3,p=2$KfOoUD89/AQhRxbwcqxUGQ$+zS4EUYI7cxOTWhA6NfdOk4i0H+GeAH/M+Ce9Jt8eag' --key='$Password_1234' --is-verbose-logging-enabled='']: should terminate" {
            $TestResult = qlogicae_cli argon2id verify --hash='$argon2id$v=19$m=65536,t=3,p=2$KfOoUD89/AQhRxbwcqxUGQ$+zS4EUYI7cxOTWhA6NfdOk4i0H+GeAH/M+Ce9Jt8eag' --key='$Password_1234' --is-verbose-logging-enabled='' | Out-String
        
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id verify --hash='$argon2id$v=19$m=65536,t=3,p=2$KfOoUD89/AQhRxbwcqxUGQ$+zS4EUYI7cxOTWhA6NfdOk4i0H+GeAH/M+Ce9Jt8eag' --key='$Password_1234' --is-verbose-logging-enabled='false']: should return true" {
            $TestResult = qlogicae_cli argon2id verify --hash='$argon2id$v=19$m=65536,t=3,p=2$KfOoUD89/AQhRxbwcqxUGQ$+zS4EUYI7cxOTWhA6NfdOk4i0H+GeAH/M+Ce9Jt8eag' --key='$Password_1234' --is-verbose-logging-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "true")) | Should -Be 1
        }

        It "[qlogicae_cli argon2id verify --hash='$argon2id$v=19$m=65536,t=3,p=2$KfOoUD89/AQhRxbwcqxUGQ$+zS4EUYI7cxOTWhA6NfdOk4i0H+GeAH/M+Ce9Jt8eag' --key='$Password_1234' --is-verbose-logging-enabled='true']: should return true" {
            $TestResult = qlogicae_cli argon2id verify --hash='$argon2id$v=19$m=65536,t=3,p=2$KfOoUD89/AQhRxbwcqxUGQ$+zS4EUYI7cxOTWhA6NfdOk4i0H+GeAH/M+Ce9Jt8eag' --key='$Password_1234' --is-verbose-logging-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "true")) | Should -Be 1
        }
    }
}
