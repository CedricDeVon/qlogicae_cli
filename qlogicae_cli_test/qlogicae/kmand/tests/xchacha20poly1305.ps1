
Describe "[qlogicae_cli xchacha20poly1305] test suite" {
    BeforeAll {
        . qlogicae/kmand/scripts/imports.ps1

        $QLogicaeKmandInstance.BeforeAllTestsSetup()
    }

    AfterAll {
        $QLogicaeKmandInstance.AfterAllTestsSetup()
    }

    Context "[qlogicae_cli xchacha20poly1305] test cases" {
        It "[qlogicae_cli xchacha20poly1305]: should throw" {
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
        It "[qlogicae_cli xchacha20poly1305 encrypt]: should throw" {
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

        It "[qlogicae_cli xchacha20poly1305 encrypt --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --text='']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --text='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli xchacha20poly1305 encrypt --text='@_The Quick Brown Fox Jumps Over The Lazy Dog' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --key='']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --text='@_The Quick Brown Fox Jumps Over The Lazy Dog' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --key='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli xchacha20poly1305 encrypt --text='@_The Quick Brown Fox Jumps Over The Lazy Dog' --key='@Password_1234' --nonce='']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --text='@_The Quick Brown Fox Jumps Over The Lazy Dog' --key='@Password_1234' --nonce='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }
        
        It "[qlogicae_cli xchacha20poly1305 encrypt --text='@_The Quick Brown Fox Jumps Over The Lazy Dog' --key='@Password_1234']: should not be null or empty" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --text='@_The Quick Brown Fox Jumps Over The Lazy Dog' --key='@Password_1234' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }

        It "[qlogicae_cli xchacha20poly1305 encrypt --text='@_The Quick Brown Fox Jumps Over The Lazy Dog' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt']: should not be null or empty" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --text='@_The Quick Brown Fox Jumps Over The Lazy Dog' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context "[qlogicae_cli xchacha20poly1305 encrypt --text --key --nonce --is-file-output-enabled] test cases" {        
        It "[qlogicae_cli xchacha20poly1305 encrypt --text='@_The Quick Brown Fox Jumps Over The Lazy Dog' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --is-file-output-enabled='']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --text='@_The Quick Brown Fox Jumps Over The Lazy Dog' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --is-file-output-enabled='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
            Test-Path ".qlogicae/cli/xchacha20poly1305-encrypt.txt" | Should -BeFalse
        }

        It "[qlogicae_cli xchacha20poly1305 encrypt --text='@_The Quick Brown Fox Jumps Over The Lazy Dog' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --is-file-output-enabled='false']: should not be null or empty" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --text='@_The Quick Brown Fox Jumps Over The Lazy Dog' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --is-file-output-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            Test-Path ".qlogicae/cli/xchacha20poly1305-encrypt.txt" | Should -BeFalse
        }

        It "[qlogicae_cli xchacha20poly1305 encrypt --text='@_The Quick Brown Fox Jumps Over The Lazy Dog' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --is-file-output-enabled='true']: should not be null or empty" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --text='@_The Quick Brown Fox Jumps Over The Lazy Dog' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --is-file-output-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            Test-Path ".qlogicae/cli/xchacha20poly1305-encrypt.txt" | Should -BeTrue
        }
    }

    Context "[qlogicae_cli xchacha20poly1305 encrypt --text --key --nonce --is-verbose-logging-enabled] test cases" {        
        It "[qlogicae_cli xchacha20poly1305 encrypt --text='@_The Quick Brown Fox Jumps Over The Lazy Dog' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --is-verbose-logging-enabled='']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --text='@_The Quick Brown Fox Jumps Over The Lazy Dog' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --is-verbose-logging-enabled='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli xchacha20poly1305 encrypt --text='@_The Quick Brown Fox Jumps Over The Lazy Dog' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --is-verbose-logging-enabled='false']: should not be null or empty" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --text='@_The Quick Brown Fox Jumps Over The Lazy Dog' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --is-verbose-logging-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }

        It "[qlogicae_cli xchacha20poly1305 encrypt --text='@_The Quick Brown Fox Jumps Over The Lazy Dog' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --is-verbose-logging-enabled='true']: should not be null or empty" {
            $TestResult = qlogicae_cli xchacha20poly1305 encrypt --text='@_The Quick Brown Fox Jumps Over The Lazy Dog' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --is-verbose-logging-enabled='true' | Out-String
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

        It "[qlogicae_cli xchacha20poly1305 decrypt --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --cipher='']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 decrypt --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --cipher='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli xchacha20poly1305 decrypt --cipher='ADXFuBXMI+Hi5HMMh6Cc/xxMunV9RSDBMl2jxfvmmZnDi6pM1UFZ7Oda1avBvOLLdDsyDT+jSbzvibI2sg==' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --key='']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 decrypt --cipher='ADXFuBXMI+Hi5HMMh6Cc/xxMunV9RSDBMl2jxfvmmZnDi6pM1UFZ7Oda1avBvOLLdDsyDT+jSbzvibI2sg==' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --key='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli xchacha20poly1305 decrypt --cipher='ADXFuBXMI+Hi5HMMh6Cc/xxMunV9RSDBMl2jxfvmmZnDi6pM1UFZ7Oda1avBvOLLdDsyDT+jSbzvibI2sg==' --key='@Password_1234' --nonce='']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 decrypt --cipher='ADXFuBXMI+Hi5HMMh6Cc/xxMunV9RSDBMl2jxfvmmZnDi6pM1UFZ7Oda1avBvOLLdDsyDT+jSbzvibI2sg==' --key='@Password_1234' --nonce='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli xchacha20poly1305 decrypt --cipher='ADXFuBXMI+Hi5HMMh6Cc/xxMunV9RSDBMl2jxfvmmZnDi6pM1UFZ7Oda1avBvOLLdDsyDT+jSbzvibI2sg==' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt']: should return '@_The Quick Brown Fox Jumps Over The Lazy Dog'" {
            $TestResult = qlogicae_cli xchacha20poly1305 decrypt --cipher='ADXFuBXMI+Hi5HMMh6Cc/xxMunV9RSDBMl2jxfvmmZnDi6pM1UFZ7Oda1avBvOLLdDsyDT+jSbzvibI2sg==' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "@_The Quick Brown Fox Jumps Over The Lazy Dog")) | Should -Be 1
        }
    }

    Context "[qlogicae_cli xchacha20poly1305 decrypt --cipher --key --nonce --is-file-output-enabled] test cases" {        
        It "[qlogicae_cli xchacha20poly1305 decrypt --cipher='ADXFuBXMI+Hi5HMMh6Cc/xxMunV9RSDBMl2jxfvmmZnDi6pM1UFZ7Oda1avBvOLLdDsyDT+jSbzvibI2sg==' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --is-file-output-enabled='']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 decrypt --cipher='ADXFuBXMI+Hi5HMMh6Cc/xxMunV9RSDBMl2jxfvmmZnDi6pM1UFZ7Oda1avBvOLLdDsyDT+jSbzvibI2sg==' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --is-file-output-enabled='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
            Test-Path ".qlogicae/cli/xchacha20poly1305-decrypt.txt" | Should -BeFalse
        }

        It "[qlogicae_cli xchacha20poly1305 decrypt --cipher='ADXFuBXMI+Hi5HMMh6Cc/xxMunV9RSDBMl2jxfvmmZnDi6pM1UFZ7Oda1avBvOLLdDsyDT+jSbzvibI2sg==' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --is-file-output-enabled='false']: should return '@_The Quick Brown Fox Jumps Over The Lazy Dog' on the console but not the file" {
            $TestResult = qlogicae_cli xchacha20poly1305 decrypt --cipher='ADXFuBXMI+Hi5HMMh6Cc/xxMunV9RSDBMl2jxfvmmZnDi6pM1UFZ7Oda1avBvOLLdDsyDT+jSbzvibI2sg==' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --is-file-output-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            Test-Path ".qlogicae/cli/xchacha20poly1305-decrypt.txt" | Should -BeFalse
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "@_The Quick Brown Fox Jumps Over The Lazy Dog")) | Should -Be 1
        }

        It "[qlogicae_cli xchacha20poly1305 decrypt --cipher='ADXFuBXMI+Hi5HMMh6Cc/xxMunV9RSDBMl2jxfvmmZnDi6pM1UFZ7Oda1avBvOLLdDsyDT+jSbzvibI2sg==' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --is-file-output-enabled='true']: should return '@_The Quick Brown Fox Jumps Over The Lazy Dog' on the console and file" {
            $TestResult = qlogicae_cli xchacha20poly1305 decrypt --cipher='ADXFuBXMI+Hi5HMMh6Cc/xxMunV9RSDBMl2jxfvmmZnDi6pM1UFZ7Oda1avBvOLLdDsyDT+jSbzvibI2sg==' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --is-file-output-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            Test-Path ".qlogicae/cli/xchacha20poly1305-decrypt.txt" | Should -BeTrue
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "@_The Quick Brown Fox Jumps Over The Lazy Dog")) | Should -Be 1
        }
    }

    Context "[qlogicae_cli xchacha20poly1305 decrypt --cipher --key --nonce --is-verbose-logging-enabled] test cases" {        
        It "[qlogicae_cli xchacha20poly1305 decrypt --cipher='ADXFuBXMI+Hi5HMMh6Cc/xxMunV9RSDBMl2jxfvmmZnDi6pM1UFZ7Oda1avBvOLLdDsyDT+jSbzvibI2sg==' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --is-verbose-logging-enabled='']: should terminate" {
            $TestResult = qlogicae_cli xchacha20poly1305 decrypt --cipher='ADXFuBXMI+Hi5HMMh6Cc/xxMunV9RSDBMl2jxfvmmZnDi6pM1UFZ7Oda1avBvOLLdDsyDT+jSbzvibI2sg==' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --is-verbose-logging-enabled='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli xchacha20poly1305 decrypt --cipher='ADXFuBXMI+Hi5HMMh6Cc/xxMunV9RSDBMl2jxfvmmZnDi6pM1UFZ7Oda1avBvOLLdDsyDT+jSbzvibI2sg==' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --is-verbose-logging-enabled='false']: should return '@_The Quick Brown Fox Jumps Over The Lazy Dog'" {
            $TestResult = qlogicae_cli xchacha20poly1305 decrypt --cipher='ADXFuBXMI+Hi5HMMh6Cc/xxMunV9RSDBMl2jxfvmmZnDi6pM1UFZ7Oda1avBvOLLdDsyDT+jSbzvibI2sg==' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --is-verbose-logging-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "@_The Quick Brown Fox Jumps Over The Lazy Dog")) | Should -Be 1
        }

        It "[qlogicae_cli xchacha20poly1305 decrypt --cipher='ADXFuBXMI+Hi5HMMh6Cc/xxMunV9RSDBMl2jxfvmmZnDi6pM1UFZ7Oda1avBvOLLdDsyDT+jSbzvibI2sg==' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --is-verbose-logging-enabled='true']: should return '@_The Quick Brown Fox Jumps Over The Lazy Dog'" {
            $TestResult = qlogicae_cli xchacha20poly1305 decrypt --cipher='ADXFuBXMI+Hi5HMMh6Cc/xxMunV9RSDBMl2jxfvmmZnDi6pM1UFZ7Oda1avBvOLLdDsyDT+jSbzvibI2sg==' --key='@Password_1234' --nonce='XfK6iU2kWh441qqTSdC4DxO1oN2lnqdt' --is-verbose-logging-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            ($QLogicaeKmandInstance.GetPatternMatchCount($TestResult, "@_The Quick Brown Fox Jumps Over The Lazy Dog")) | Should -Be 1
        }
    }
}
