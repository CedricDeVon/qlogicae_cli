
Describe "[qlogicae_cli windows-registry] test suite" {
    BeforeAll {
        . $PSScriptRoot/imports.ps1

        $QLogicaeKmandInstance.BeforeAllTestsSetup()
    }

    AfterAll {
        $QLogicaeKmandInstance.AfterAllTestsSetup()
    }

    Context ("[qlogicae_cli windows-registry] test cases") {
        It "[qlogicae_cli windows-registry]: should terminate" {
            $TestResult = qlogicae_cli windows-registry | Out-String        

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry --help]: should not be null or empty" {
            $TestResult = qlogicae_cli windows-registry --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli windows-registry hkcu] test cases") {
        It "[qlogicae_cli windows-registry hkcu]: should terminate" {
            $TestResult = qlogicae_cli windows-registry hkcu | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu --help]: should not be null or empty" {
            $TestResult = qlogicae_cli windows-registry hkcu --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli windows-registry hkcu get] test cases") {
        It "[qlogicae_cli windows-registry hkcu get]: should terminate" {
            $TestResult = qlogicae_cli windows-registry hkcu get | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu get --help]: should not be null or empty" {
            $TestResult = qlogicae_cli windows-registry hkcu get --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli windows-registry hkcu get --sub-path] test cases") {
        It "[qlogicae_cli windows-registry hkcu get --sub-path='']: should terminate" {
            $TestResult = qlogicae_cli windows-registry hkcu get --sub-path='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu get --sub-path='a']: should terminate" {
            $TestResult = qlogicae_cli windows-registry hkcu get --sub-path='a' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu get --sub-path='Environment']: should not be null or empty" {
            $TestResult = qlogicae_cli windows-registry hkcu get --sub-path='Environment' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli windows-registry hkcu get --sub-path --is-verbose-logging-enabled] test cases") {
        It "[qlogicae_cli windows-registry hkcu get --sub-path='Environment' --is-verbose-logging-enabled='']: should terminate" {
            $TestResult = qlogicae_cli windows-registry hkcu get --sub-path='Environment' --is-verbose-logging-enabled='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu get --sub-path='Environment' --is-verbose-logging-enabled='false']: should not be null or empty" {
            $TestResult = qlogicae_cli windows-registry hkcu get --sub-path='Environment' --is-verbose-logging-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu get --sub-path='Environment' --is-verbose-logging-enabled='true']: should not be null or empty" {
            $TestResult = qlogicae_cli windows-registry hkcu get --sub-path='Environment' --is-verbose-logging-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }


    Context ("[qlogicae_cli windows-registry hkcu set] test cases") {
        It "[qlogicae_cli windows-registry hkcu set]: should terminate" {
            $TestResult = qlogicae_cli windows-registry hkcu set | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu set --help]: should not be null or empty" {
            $TestResult = qlogicae_cli windows-registry hkcu set --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli windows-registry hkcu set --environment-type] test cases") {
        It "[qlogicae_cli windows-registry hkcu set --environment-type='']: should terminate" {
            $TestResult = qlogicae_cli windows-registry hkcu set --environment-type='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu set --environment-type='a']: should terminate" {
            $TestResult = qlogicae_cli windows-registry hkcu set --environment-type='a' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu set --environment-type='development']: should be null or empty" {
            $TestResult = qlogicae_cli windows-registry hkcu set --environment-type='development' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu set --environment-type='debug']: should be null or empty" {
            $TestResult = qlogicae_cli windows-registry hkcu set --environment-type='debug' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }
        
        It "[qlogicae_cli windows-registry hkcu set --environment-type='test']: should be null or empty" {
            $TestResult = qlogicae_cli windows-registry hkcu set --environment-type='test' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu set --environment-type='release']: should be null or empty" {
            $TestResult = qlogicae_cli windows-registry hkcu set --environment-type='release' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu set --environment-type='all']: should be null or empty" {
            $TestResult = qlogicae_cli windows-registry hkcu set --environment-type='all' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }
    }
    
    Context ("[qlogicae_cli windows-registry hkcu set --environment-type --is-verbose-logging-enabled] test cases") {   
        It "[qlogicae_cli windows-registry hkcu set --environment-type='development' --is-verbose-logging-enabled='']: should terminate" {
            $TestResult = qlogicae_cli windows-registry hkcu set --environment-type='development' --is-verbose-logging-enabled='' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu set --environment-type='development' --is-verbose-logging-enabled='false']: should be null or empty" {
            $TestResult = qlogicae_cli windows-registry hkcu set --environment-type='development' --is-verbose-logging-enabled='false' | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli windows-registry hkcu set --environment-type='development' --is-verbose-logging-enabled='true']: should not be null or empty" {
            $TestResult = qlogicae_cli windows-registry hkcu set --environment-type='development' --is-verbose-logging-enabled='true' | Out-String

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }
}
