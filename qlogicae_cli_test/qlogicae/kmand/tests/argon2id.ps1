
Describe "[qlogicae_cli argon2id] test suite" {
    BeforeAll {
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

        It "[qlogicae_cli argon2id hash --text='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)']: should generate an argon2id hash" {
            $TestResult = qlogicae_cli argon2id hash --text="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "argon2id")) | Should -Be 1
        }
    }

    Context "[qlogicae_cli argon2id hash --text --is-file-output-enabled] test cases" {
        It "[qlogicae_cli argon2id hash --text='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)' --is-file-output-enabled='']: terminate" {
            $TestResult = qlogicae_cli argon2id hash --text="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" --is-file-output-enabled='' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id hash --text='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)' --is-file-output-enabled='fals']: terminate" {
            $TestResult = qlogicae_cli argon2id hash --text="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" --is-file-output-enabled='fals' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id hash --text='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)' --is-file-output-enabled='tru']: terminate" {
            $TestResult = qlogicae_cli argon2id hash --text="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" --is-file-output-enabled='tru' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id hash --text='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)' --is-file-output-enabled='false']: should generate an argon2id hash" {
            $TestResult = qlogicae_cli argon2id hash --text="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" --is-file-output-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "argon2id")) | Should -Be 1
            Test-Path "$($QLogicaeKmandInstance.Configurations.RelativeDotQLogicaeArgon2IDHashFilePath)" | Should -BeFalse
        }

        It "[qlogicae_cli argon2id hash --text='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)' --is-file-output-enabled='true']: should generate an argon2id hash" {
            $TestResult = qlogicae_cli argon2id hash --text="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" --is-file-output-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "argon2id")) | Should -Be 1
            Test-Path "$($QLogicaeKmandInstance.Configurations.RelativeDotQLogicaeArgon2IDHashFilePath)" | Should -BeTrue
        }
    }

    Context "[qlogicae_cli argon2id hash --text --is-file-output-enabled --output-file-path] test cases" {
        It "[qlogicae_cli argon2id hash --text='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)' --is-file-output-enabled='true' --output-file-path='']: terminate" {
            $TestResult = qlogicae_cli argon2id hash --text="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" --is-file-output-enabled='true' --output-file-path='' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id hash --text='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)' --is-file-output-enabled='true' --output-file-path='$($QLogicaeKmandInstance.Configurations.RelativeDotQLogicaeCLICustomOutputFilePath)']: should generate an argon2id hash" {
            $TestResult = qlogicae_cli argon2id hash --text="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" --is-file-output-enabled='true' --output-file-path="$($QLogicaeKmandInstance.Configurations.RelativeDotQLogicaeCLICustomOutputFilePath)" | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "argon2id")) | Should -Be 1
            Test-Path "$($QLogicaeKmandInstance.Configurations.RelativeDotQLogicaeCLICustomOutputFilePath)" | Should -BeTrue
        }
    }
    
    Context "[qlogicae_cli argon2id hash --text --is-verbose-logging-enabled] test cases" {
        It "[qlogicae_cli argon2id hash --text='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)' --is-verbose-logging-enabled='']: should terminate" {
            $TestResult = qlogicae_cli argon2id hash --text="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" --is-verbose-logging-enabled='' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id hash --text='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)' --is-verbose-logging-enabled='fals']: should terminate" {
            $TestResult = qlogicae_cli argon2id hash --text="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" --is-verbose-logging-enabled='fals' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id hash --text='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)' --is-verbose-logging-enabled='tru']: should terminate" {
            $TestResult = qlogicae_cli argon2id hash --text="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" --is-verbose-logging-enabled='tru' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id hash --text='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)' --is-verbose-logging-enabled='false']: should generate an argon2id hash" {
            $TestResult = qlogicae_cli argon2id hash --text="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" --is-verbose-logging-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "argon2id")) | Should -Be 1
        }

        It "[qlogicae_cli argon2id hash --text='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)' --is-verbose-logging-enabled='true']: should generate an argon2id hash" {
            $TestResult = qlogicae_cli argon2id hash --text="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" --is-verbose-logging-enabled='true' | Out-String
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

        It "[qlogicae_cli argon2id verify --key='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)' --hash='']: should terminate" {
            $TestResult = qlogicae_cli argon2id verify --key="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" --hash='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id verify --hash='$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)' --key='']: should terminate" {
            $TestResult = qlogicae_cli argon2id verify --hash="$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)" --key='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }
        
        It "[qlogicae_cli argon2id verify --hash='a' --key='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)']: should return 'false'" {
            $TestResult = qlogicae_cli argon2id verify --hash='a' --key="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "false")) | Should -Be 1
        }

        It "[qlogicae_cli argon2id verify --hash='$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)' --key='a']: should return 'false'" {
            $TestResult = qlogicae_cli argon2id verify --hash="$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)" --key='a' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "false")) | Should -Be 1
        }

        It "[qlogicae_cli argon2id verify --hash='$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)' --key='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)']: should return 'true'" {
            $TestResult = qlogicae_cli argon2id verify --hash="$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)" --key="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "true")) | Should -Be 1
        }
    }

    Context "[qlogicae_cli argon2id verify --hash --key --is-verbose-logging-enabled] test cases" {  
        It "[qlogicae_cli argon2id verify --hash='$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)' --key='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)' --is-verbose-logging-enabled='']: should terminate" {
            $TestResult = qlogicae_cli argon2id verify --hash="$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)" --key="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" --is-verbose-logging-enabled='' | Out-String
        
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id verify --hash='$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)' --key='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)' --is-verbose-logging-enabled='fals']: should terminate" {
            $TestResult = qlogicae_cli argon2id verify --hash="$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)" --key="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" --is-verbose-logging-enabled='fals' | Out-String
        
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id verify --hash='$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)' --key='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)' --is-verbose-logging-enabled='tru']: should terminate" {
            $TestResult = qlogicae_cli argon2id verify --hash="$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)" --key="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" --is-verbose-logging-enabled='tru' | Out-String
        
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id verify --hash='$($QLogicaeKmandInstance.Configurations.MMockArgon2IDHash)' --key='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)' --is-verbose-logging-enabled='false']: should return 'false'" {
            $TestResult = qlogicae_cli argon2id verify --hash="$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)" --key="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" --is-verbose-logging-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "true")) | Should -Be 1
        }

        It "[qlogicae_cli argon2id verify --hash='$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)' --key='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)' --is-verbose-logging-enabled='true']: should return 'true'" {
            $TestResult = qlogicae_cli argon2id verify --hash="$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)" --key="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" --is-verbose-logging-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -BeGreaterOrEqual 1
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "true")) | Should -Be 1
        }
    }
    
    Context "[qlogicae_cli argon2id verify --hash --key --is-file-output-enabled] test cases" {
        It "[qlogicae_cli argon2id verify --hash='$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)' --key='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)' --is-file-output-enabled='']: should terminate" {
            $TestResult = qlogicae_cli argon2id verify --hash="$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)" --key="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" --is-file-output-enabled='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id verify --hash='$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)' --key='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)' --is-file-output-enabled='fals']: should terminate" {
            $TestResult = qlogicae_cli argon2id verify --hash="$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)" --key="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" --is-file-output-enabled='fals' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id verify --hash='$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)' --key='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)' --is-file-output-enabled='tru']: should terminate" {
            $TestResult = qlogicae_cli argon2id verify --hash="$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)" --key="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" --is-file-output-enabled='tru' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id verify --hash='$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)' --key='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)' --is-file-output-enabled='true']: should generate 1 instance(s) on the console except the file" {
            $TestResult = qlogicae_cli argon2id verify --hash="$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)" --key="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" --is-file-output-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            Test-Path "$($QLogicaeKmandInstance.Configurations.RelativeDotQLogicaeArgon2IDVerifyFilePath)" | Should -BeFalse
        }

        It "[qlogicae_cli argon2id verify --hash='$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)' --key='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)' --is-file-output-enabled='true']: should generate 1 instance(s) on the console and file" {
            $TestResult = qlogicae_cli argon2id verify --hash="$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)" --key="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" --is-file-output-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            Test-Path "$($QLogicaeKmandInstance.Configurations.RelativeDotQLogicaeArgon2IDVerifyFilePath)" | Should -BeTrue
        }
    }

    Context "[qlogicae_cli argon2id verify --hash --key --is-file-output-enabled --output-file-path] test cases" {
        It "[qlogicae_cli argon2id verify --hash='$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)' --key='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)' --is-file-output-enabled='true' --output-file-path='']: should terminate" {
            $TestResult = qlogicae_cli argon2id verify --hash="$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)" --key="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" --is-file-output-enabled='true' --output-file-path='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli argon2id verify --hash='$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)' --key='$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)' --is-file-output-enabled='true' --output-file-path='$($QLogicaeKmandInstance.Configurations.RelativeDotQLogicaeCLICustomOutputFilePath)']: should generate 1 instance(s) on the console and file" {
            $TestResult = qlogicae_cli argon2id verify --hash="$($QLogicaeKmandInstance.Configurations.MockArgon2IDHash)" --key="$($QLogicaeKmandInstance.Configurations.MockArgon2IDText)" --is-file-output-enabled='true' --output-file-path="$($QLogicaeKmandInstance.Configurations.RelativeDotQLogicaeCLICustomOutputFilePath)" | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetLineCount($TestResult)) | Should -Be 1
            Test-Path "$($QLogicaeKmandInstance.Configurations.RelativeDotQLogicaeCLICustomOutputFilePath)" | Should -BeTrue
        }
    }
}
