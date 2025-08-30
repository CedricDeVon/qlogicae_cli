
Describe "[qlogicae_cli string] test suite" {
    BeforeAll {
        . qlogicae/kmand/scripts/imports.ps1

        $QLogicaeKmandInstance.BeforeAllTestsSetup()
        
        qlogicae_cli setup vs2022 application
    }

    AfterAll {
        $QLogicaeKmandInstance.AfterAllTestsSetup()
    }

    Context "[qlogicae_cli scripts] test cases" {
        It "[qlogicae_cli scripts]: should terminate" {
            $TestResult = qlogicae_cli scripts | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli scripts --help]: should not be null or empty" {
            $TestResult = qlogicae_cli scripts --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context "[qlogicae_cli scripts run] test cases" {
        It "[qlogicae_cli scripts run]: should terminate" {
            $TestResult = qlogicae_cli scripts run | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli scripts run --help]: should not be null or empty" {
            $TestResult = qlogicae_cli scripts run --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context "[qlogicae_cli scripts run --names] test cases" {
        It "[qlogicae_cli scripts run --names='']: should terminate" {
            $TestResult = qlogicae_cli scripts run --names='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli scripts run --names='sample,none']: should terminate" {
            $TestResult = qlogicae_cli scripts run --names='sample,none' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }

        It "[qlogicae_cli scripts run --names='sample']: should not be null or empty" {
            $TestResult = qlogicae_cli scripts run --names='sample' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }        
    }

    Context "[qlogicae_cli scripts run --names --is-verbose-logging-enabled] test cases" {
        It "[qlogicae_cli scripts run --names --is-verbose-logging-enabled='']: should terminate" {
            $TestResult = qlogicae_cli scripts run --names='sample' --is-verbose-logging-enabled='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli scripts run --names --is-verbose-logging-enabled='false']: should not be null or empty" {
            $TestResult = qlogicae_cli scripts run --names='sample' --is-verbose-logging-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
        
        It "[qlogicae_cli scripts run --names --is-verbose-logging-enabled='true']: should not be null or empty" {
            $TestResult = qlogicae_cli scripts run --names='sample' --is-verbose-logging-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }
}
