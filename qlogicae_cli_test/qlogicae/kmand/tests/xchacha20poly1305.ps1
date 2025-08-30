
Describe "[qlogicae_cli xchacha20poly1305] test suite" {
    BeforeAll {
        $QLogicaeKmandInstance.BeforeAllTestsSetup()
    }

    AfterAll {
        $QLogicaeKmandInstance.AfterAllTestsSetup()
    }

    Context "[qlogicae_cli xchacha20poly1305] test cases" {
        It "[qlogicae_cli xchacha20poly1305]: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli xchacha20poly1305 --help]: should not be null or empty" {
            $TestResult = qlogicae_cli xchacha20poly1305 --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context "[qlogicae_cli xchacha20poly1305 encrypt] test cases" {
        It "[qlogicae_cli xchacha20poly1305 encrypt]: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli xchacha20poly1305 encrypt --help]: should not be null or empty" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context "[qlogicae_cli xchacha20poly1305 encrypt --text --key --nonce] test cases" {
        It "[qlogicae_cli xchacha20poly1305 encrypt --text='' --key='' --nonce='']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --text='' --key='' --nonce='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli xchacha20poly1305 encrypt --key='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)' --nonce='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)' --text='']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --key="($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)" -nonce="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)" --text='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli xchacha20poly1305 encrypt --text='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)' --nonce='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)' --key='']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --text="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)" --nonce="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)" --key='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli xchacha20poly1305 encrypt --text='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)' --key='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)' --nonce='']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --text="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)" --key="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)" --nonce='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }
        
        It "[qlogicae_cli xchacha20poly1305 encrypt --text='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)' --key='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)']: should not be null or empty" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --text="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)" --key="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)" | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }

        It "[qlogicae_cli xchacha20poly1305 encrypt --text='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)' --key='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)' --nonce='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)']: should not be null or empty" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --text="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)" --key="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)" --nonce="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)" | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context "[qlogicae_cli xchacha20poly1305 encrypt --text --key --nonce --is-file-output-enabled] test cases" {        
        It "[qlogicae_cli xchacha20poly1305 encrypt --text='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)' --key='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)' --nonce='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)' --is-file-output-enabled='']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --text="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)" --key="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)" --nonce="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)" --is-file-output-enabled='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
            Test-Path "$($QLogicaeKmandInstance.Configurations.RelativeDotQLogicaeXChaCha20Poly1305EncryptFilePath)" | Should -BeFalse
        }

        It "[qlogicae_cli xchacha20poly1305 encrypt --text='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)' --key='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)' --nonce='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)' --is-file-output-enabled='fals']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --text="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)" --key="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)" --nonce="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)" --is-file-output-enabled='fals' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
            Test-Path "$($QLogicaeKmandInstance.Configurations.RelativeDotQLogicaeXChaCha20Poly1305EncryptFilePath)" | Should -BeFalse
        }

        It "[qlogicae_cli xchacha20poly1305 encrypt --text='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)' --key='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)' --nonce='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)' --is-file-output-enabled='tru']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --text="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)" --key="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)" --nonce="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)" --is-file-output-enabled='tru' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
            Test-Path "$($QLogicaeKmandInstance.Configurations.RelativeDotQLogicaeXChaCha20Poly1305EncryptFilePath)" | Should -BeFalse
        }

        It "[qlogicae_cli xchacha20poly1305 encrypt --text='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)' --key='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)' --nonce='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)' --is-file-output-enabled='false']: should not be null or empty" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --text="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)" --key="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)" --nonce="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)" --is-file-output-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            Test-Path "$($QLogicaeKmandInstance.Configurations.RelativeDotQLogicaeXChaCha20Poly1305EncryptFilePath)" | Should -BeFalse
        }

        It "[qlogicae_cli xchacha20poly1305 encrypt --text='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)' --key='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)' --nonce='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)' --is-file-output-enabled='true']: should not be null or empty" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --text="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)" --key="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)" --nonce="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)" --is-file-output-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            Test-Path "$($QLogicaeKmandInstance.Configurations.RelativeDotQLogicaeXChaCha20Poly1305EncryptFilePath)" | Should -BeTrue
        }
    }

    Context "[qlogicae_cli xchacha20poly1305 encrypt --text --key --nonce --is-verbose-logging-enabled] test cases" {        
        It "[qlogicae_cli xchacha20poly1305 encrypt --text='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)' --key='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)' --nonce='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)' --is-verbose-logging-enabled='']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --text="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)" --key="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)" --nonce="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)" --is-verbose-logging-enabled='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli xchacha20poly1305 encrypt --text='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)' --key='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)' --nonce='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)' --is-verbose-logging-enabled='fals']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --text="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)" --key="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)" --nonce="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)" --is-verbose-logging-enabled='fals' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli xchacha20poly1305 encrypt --text='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)' --key='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)' --nonce='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)' --is-verbose-logging-enabled='tru']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --text="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)" --key="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)" --nonce="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)" --is-verbose-logging-enabled='tru' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli xchacha20poly1305 encrypt --text='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)' --key='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)' --nonce='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)' --is-verbose-logging-enabled='false']: should not be null or empty" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --text="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)" --key="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)" --nonce="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)" --is-verbose-logging-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }

        It "[qlogicae_cli xchacha20poly1305 encrypt --text='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)' --key='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)' --nonce='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)' --is-verbose-logging-enabled='true']: should not be null or empty" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --text="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)" --key="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)" --nonce="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)" --is-verbose-logging-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context "[qlogicae_cli xchacha20poly1305 decrypt] test cases" {
        It "[qlogicae_cli xchacha20poly1305 decrypt]: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 decrypt | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli xchacha20poly1305 decrypt --help]: should not be null or empty" {
            $TestResult = qlogicae_cli xchacha20poly1305 decrypt --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }
    
    Context "[qlogicae_cli xchacha20poly1305 decrypt --cipher --key --nonce] test cases" {
        It "[qlogicae_cli xchacha20poly1305 decrypt --cipher='' --key='' --nonce='']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 decrypt --cipher='' --key='' --nonce='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli xchacha20poly1305 decrypt --key='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)' --nonce='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)' --cipher='']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 decrypt --key="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)" --nonce="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)" --cipher='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli xchacha20poly1305 decrypt --cipher='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Cipher)' --nonce='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)' --key='']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 decrypt --cipher="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Cipher)" --nonce="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)" --key='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli xchacha20poly1305 decrypt --cipher='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Cipher)' --key='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)' --nonce='']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 decrypt --cipher="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Cipher)" --key="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)" --nonce='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli xchacha20poly1305 decrypt --cipher='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Cipher)' --key='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)' --nonce='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)']: should return '$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)'" {
            $TestResult = qlogicae_cli xchacha20poly1305 decrypt --cipher="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Cipher)" --key="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)" --nonce="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)" | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)")) | Should -Be 1
        }
    }

    Context "[qlogicae_cli xchacha20poly1305 decrypt --cipher --key --nonce --is-file-output-enabled] test cases" {        
        It "[qlogicae_cli xchacha20poly1305 decrypt --cipher='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Cipher)' --key='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)' --nonce='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)' --is-file-output-enabled='']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 decrypt --cipher="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Cipher)" --key="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)" --nonce="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)" --is-file-output-enabled='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
            Test-Path "$($QLogicaeKmandInstance.Configurations.RelativeDotQLogicaeXChaCha20Poly1305DecryptFilePath)" | Should -BeFalse
        }

        It "[qlogicae_cli xchacha20poly1305 decrypt --cipher='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Cipher)' --key='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)' --nonce='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)' --is-file-output-enabled='fals']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 decrypt --cipher="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Cipher)" --key="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)" --nonce="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)" --is-file-output-enabled='fals' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
            Test-Path "$($QLogicaeKmandInstance.Configurations.RelativeDotQLogicaeXChaCha20Poly1305DecryptFilePath)" | Should -BeFalse
        }

        It "[qlogicae_cli xchacha20poly1305 decrypt --cipher='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Cipher)' --key='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)' --nonce='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)' --is-file-output-enabled='tru']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 decrypt --cipher="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Cipher)" --key="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)" --nonce="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)" --is-file-output-enabled='tru' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
            Test-Path "$($QLogicaeKmandInstance.Configurations.RelativeDotQLogicaeXChaCha20Poly1305DecryptFilePath)" | Should -BeFalse
        }

        It "[qlogicae_cli xchacha20poly1305 decrypt --cipher='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Cipher)' --key='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)' --nonce='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)' --is-file-output-enabled='false']: should return '$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)' on the console but not the file" {
            $TestResult = qlogicae_cli xchacha20poly1305 decrypt --cipher="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Cipher)" --key="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)" --nonce="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)" --is-file-output-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            Test-Path "$($QLogicaeKmandInstance.Configurations.RelativeDotQLogicaeXChaCha20Poly1305DecryptFilePath)" | Should -BeFalse
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)")) | Should -Be 1
        }

        It "[qlogicae_cli xchacha20poly1305 decrypt --cipher='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Cipher)' --key='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)' --nonce='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)' --is-file-output-enabled='true']: should return '$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)' on the console and file" {
            $TestResult = qlogicae_cli xchacha20poly1305 decrypt --cipher="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Cipher)" --key="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)" --nonce="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)" --is-file-output-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            Test-Path "$($QLogicaeKmandInstance.Configurations.RelativeDotQLogicaeXChaCha20Poly1305DecryptFilePath)" | Should -BeTrue
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)")) | Should -Be 1
        }
    }

    Context "[qlogicae_cli xchacha20poly1305 decrypt --cipher --key --nonce --is-verbose-logging-enabled] test cases" {        
        It "[qlogicae_cli xchacha20poly1305 decrypt --cipher='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Cipher)' --key='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)' --nonce='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)' --is-verbose-logging-enabled='']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 decrypt --cipher="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Cipher)" --key="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)" --nonce="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)" --is-verbose-logging-enabled='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }
        
        It "[qlogicae_cli xchacha20poly1305 decrypt --cipher='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Cipher)' --key='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)' --nonce='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)' --is-verbose-logging-enabled='fals']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 decrypt --cipher="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Cipher)" --key="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)" --nonce="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)" --is-verbose-logging-enabled='fals' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli xchacha20poly1305 decrypt --cipher='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Cipher)' --key='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)' --nonce='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)' --is-verbose-logging-enabled='tru']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 decrypt --cipher="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Cipher)" --key="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)" --nonce="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)" --is-verbose-logging-enabled='tru' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli xchacha20poly1305 decrypt --cipher='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Cipher)' --key='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)' --nonce='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)' --is-verbose-logging-enabled='false']: should return '$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)'" {
            $TestResult = qlogicae_cli xchacha20poly1305 decrypt --cipher="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Cipher)" --key="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)" --nonce="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)" --is-verbose-logging-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)")) | Should -Be 1
        }

        It "[qlogicae_cli xchacha20poly1305 decrypt --cipher='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Cipher)' --key='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)' --nonce='$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)' --is-verbose-logging-enabled='true']: should return '$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)'" {
            $TestResult = qlogicae_cli xchacha20poly1305 decrypt --cipher="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Cipher)" --key="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Key)" --nonce="$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Nonce)" --is-verbose-logging-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "$($QLogicaeKmandInstance.Configurations.MockXChaCha20Poly1305Text)")) | Should -Be 1
        }
    }
}
