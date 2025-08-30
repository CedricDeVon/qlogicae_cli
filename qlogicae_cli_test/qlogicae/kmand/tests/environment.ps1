
Describe "[qlogicae_cli environment] test suite" {
    BeforeAll {
        . qlogicae/kmand/scripts/imports.ps1

        $QLogicaeKmandInstance.BeforeAllTestsSetup()

        qlogicae_cli setup vs2022 application
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

        It "[qlogicae_cli environment set --type='development']: should set 'environment.selected' property to 'development'" {
            $TestResult = qlogicae_cli environment set --type='development' | Out-String           

            $TestResult | Should -BeNullOrEmpty
            (Get-Content "$($QLogicaeKmandInstance.Configurations.RelativeQLogicaeConfigurationsPublicFilePath)" -Raw | ConvertFrom-Json).environment.selected | Should -Be "development"
        }

        It "[qlogicae_cli environment set --type='debug']: should set 'environment.selected' property to 'debug'" {
            $TestResult = qlogicae_cli environment set --type='debug' | Out-String           

            $TestResult | Should -BeNullOrEmpty
            (Get-Content "$($QLogicaeKmandInstance.Configurations.RelativeQLogicaeConfigurationsPublicFilePath)" -Raw | ConvertFrom-Json).environment.selected | Should -Be "debug"
        }

        It "[qlogicae_cli environment set --type='test']: should set 'environment.selected' property to 'test'" {
            $TestResult = qlogicae_cli environment set --type='test' | Out-String           

            $TestResult | Should -BeNullOrEmpty
            (Get-Content "$($QLogicaeKmandInstance.Configurations.RelativeQLogicaeConfigurationsPublicFilePath)" -Raw | ConvertFrom-Json).environment.selected | Should -Be "test"
        }

        It "[qlogicae_cli environment set --type='release']: should set 'environment.selected' property to 'release'" {
            $TestResult = qlogicae_cli environment set --type='release' | Out-String           

            $TestResult | Should -BeNullOrEmpty
            (Get-Content "$($QLogicaeKmandInstance.Configurations.RelativeQLogicaeConfigurationsPublicFilePath)" -Raw | ConvertFrom-Json).environment.selected | Should -Be "release"
        }
    }
    
    Context "[qlogicae_cli environment set --type --is-verbose-logging-enabled] test cases" {
        It "[qlogicae_cli environment set --type='development' --is-verbose-logging-enabled='']: should terminate" {
            $TestResult = qlogicae_cli environment set --type='development' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli environment set --type='development' --is-verbose-logging-enabled='false']: should set 'environment.selected' property to 'development'" {
            $TestResult = qlogicae_cli environment set --type='development' --is-verbose-logging-enabled='false' | Out-String           

            $TestResult | Should -BeNullOrEmpty
            (Get-Content "$($QLogicaeKmandInstance.Configurations.RelativeQLogicaeConfigurationsPublicFilePath)" -Raw | ConvertFrom-Json).environment.selected | Should -Be "development"
        }

        It "[qlogicae_cli environment set --type='development' --is-verbose-logging-enabled='true']: should set 'environment.selected' property to 'development'" {
            $TestResult = qlogicae_cli environment set --type='development' --is-verbose-logging-enabled='true' | Out-String           

            $TestResult | Should -Not -BeNullOrEmpty
            (Get-Content "$($QLogicaeKmandInstance.Configurations.RelativeQLogicaeConfigurationsPublicFilePath)" -Raw | ConvertFrom-Json).environment.selected | Should -Be "development"
        }
    }    
}
