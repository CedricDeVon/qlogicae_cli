
Describe "[qlogicae_cli string] test suite" {
    BeforeAll {
        . $PSScriptRoot/imports.ps1

        $QLogicaeKmandInstance.BeforeAllTestsSetup()
    }

    AfterAll {
        $QLogicaeKmandInstance.AfterAllTestsSetup()
    }

    Context "[qlogicae_cli environment] test cases" {
        It "[qlogicae_cli environment]: should terminate" {
            $TestResult = qlogicae_cli environment | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli environment --help]: should not be null or empty" {
            $TestResult = qlogicae_cli environment --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context "[qlogicae_cli environment set] test cases" {
        It "[qlogicae_cli environment set]: should terminate" {
            $TestResult = qlogicae_cli environment set | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli environment set --help]: should not be null or empty" {
            $TestResult = qlogicae_cli environment set --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context "[qlogicae_cli environment set --type] test cases" {
        It "[qlogicae_cli environment set --type='']: should terminate" {
            $TestResult = qlogicae_cli environment set --type='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli environment set --type='a']: should terminate" {
            $TestResult = qlogicae_cli environment set --type='a' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli environment set --type='development']: should set 'environment.selected' propery to 'development'" {
            $TestResult = qlogicae_cli environment set --type='development' | Out-String           

            (Get-Content "$($QLogicaeKmandInstance.Configurations.QLogicaeConfigurationsPublicFilePath)" -Raw | ConvertFrom-Json).environment.selected | Should -Be "development"
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli environment set --type='debug']: should set 'environment.selected' propery to 'debug'" {
            $TestResult = qlogicae_cli environment set --type='debug' | Out-String           

            (Get-Content "$($QLogicaeKmandInstance.Configurations.QLogicaeConfigurationsPublicFilePath)" -Raw | ConvertFrom-Json).environment.selected | Should -Be "debug"
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli environment set --type='test']: should set 'environment.selected' propery to 'test'" {
            $TestResult = qlogicae_cli environment set --type='test' | Out-String           

            (Get-Content "$($QLogicaeKmandInstance.Configurations.QLogicaeConfigurationsPublicFilePath)" -Raw | ConvertFrom-Json).environment.selected | Should -Be "test"
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli environment set --type='release']: should set 'environment.selected' propery to 'release'" {
            $TestResult = qlogicae_cli environment set --type='release' | Out-String           

            (Get-Content "$($QLogicaeKmandInstance.Configurations.QLogicaeConfigurationsPublicFilePath)" -Raw | ConvertFrom-Json).environment.selected | Should -Be "release"
            $TestResult | Should -BeNullOrEmpty
        }
    }
    
    Context "[qlogicae_cli environment set --type --is-verbose-logging-enabled] test cases" {
        It "[qlogicae_cli environment set --type='development' --is-verbose-logging-enabled='']: should terminate" {
            $TestResult = qlogicae_cli environment set --type='development' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli environment set --type='development' --is-verbose-logging-enabled='false']: should set 'environment.selected' propery to 'development'" {
            $TestResult = qlogicae_cli environment set --type='development' --is-verbose-logging-enabled='false' | Out-String           

            (Get-Content "$($QLogicaeKmandInstance.Configurations.QLogicaeConfigurationsPublicFilePath)" -Raw | ConvertFrom-Json).environment.selected | Should -Be "development"
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli environment set --type='development' --is-verbose-logging-enabled='true']: should set 'environment.selected' propery to 'development'" {
            $TestResult = qlogicae_cli environment set --type='development' --is-verbose-logging-enabled='true' | Out-String           

            (Get-Content "$($QLogicaeKmandInstance.Configurations.QLogicaeConfigurationsPublicFilePath)" -Raw | ConvertFrom-Json).environment.selected | Should -Be "development"
            $TestResult | Should -Not -BeNullOrEmpty
        }
    }    
}
