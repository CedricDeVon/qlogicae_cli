
Describe "[qlogicae_cli setup] test suite" {
    BeforeAll {
        . qlogicae/kmand/scripts/imports.ps1

        $QLogicaeKmandInstance.BeforeAllTestsSetup()
    }

    AfterAll {
        $QLogicaeKmandInstance.AfterAllTestsSetup()
    }

    Context ("[qlogicae_cli setup] test cases") {
        It "[qlogicae_cli setup]: should terminate" {
            $TestResult = qlogicae_cli setup | Out-String        

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli setup --help]: should not be null or empty" {
            $TestResult = qlogicae_cli setup --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli setup generic] test cases") {
        It "[qlogicae_cli setup generic]: should terminate" {
            $TestResult = qlogicae_cli setup generic | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli setup generic --help]: should not be null or empty" {
            $TestResult = qlogicae_cli setup vs2022 --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli setup generic documentation] test cases") {
        It "[qlogicae_cli setup generic documentation --help]: should not be null or empty" {
            $TestResult = qlogicae_cli setup generic documentation --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }

        It "[qlogicae_cli setup generic documentation]: should not leave an empty folder" {
            $TestResult = qlogicae_cli setup generic documentation | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            $QLogicaeKmandInstance.IsFolderEmpty("$($QLogicaeKmandInstance.Configurations.DotQLogicaeKmandEnvironmentFolderPath)") | Should -Be $false
        }
    }

    Context ("[qlogicae_cli setup generic documentation --is-verbose-logging-enabled] test cases") {        
        It "[qlogicae_cli setup generic documentation --is-verbose-logging-enabled='']: should not leave an empty folder" {
            $TestResult = qlogicae_cli setup generic documentation --is-verbose-logging-enabled='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli setup generic documentation --is-verbose-logging-enabled='fals']: should not leave an empty folder" {
            $TestResult = qlogicae_cli setup generic documentation --is-verbose-logging-enabled='fals' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli setup generic documentation --is-verbose-logging-enabled='tru']: should not leave an empty folder" {
            $TestResult = qlogicae_cli setup generic documentation --is-verbose-logging-enabled='tru' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli setup generic documentation --is-verbose-logging-enabled='false']: should not leave an empty folder" {
            $TestResult = qlogicae_cli setup generic documentation --is-verbose-logging-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            $QLogicaeKmandInstance.IsFolderEmpty("$($QLogicaeKmandInstance.Configurations.DotQLogicaeKmandEnvironmentFolderPath)") | Should -Be $false
        }

        It "[qlogicae_cli setup vs2022 application --is-verbose-logging-enabled='true']: should not leave an empty folder" {
            $TestResult = qlogicae_cli setup vs2022 application --is-verbose-logging-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            $QLogicaeKmandInstance.IsFolderEmpty("$($QLogicaeKmandInstance.Configurations.DotQLogicaeKmandEnvironmentFolderPath)") | Should -Be $false
        }
    }

    Context ("[qlogicae_cli setup vs2022] test cases") {
        It "[qlogicae_cli setup vs2022]: should terminate" {
            $TestResult = qlogicae_cli setup vs2022 | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli setup vs2022 --help]: should not be null or empty" {
            $TestResult = qlogicae_cli setup vs2022 --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli setup vs2022 application] test cases") {
        It "[qlogicae_cli setup vs2022 application --help]: should not be null or empty" {
            $TestResult = qlogicae_cli setup vs2022 application --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }

        It "[qlogicae_cli setup vs2022 application]: should not leave an empty folder" {
            $TestResult = qlogicae_cli setup vs2022 application | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            $QLogicaeKmandInstance.IsFolderEmpty("$($QLogicaeKmandInstance.Configurations.DotQLogicaeKmandEnvironmentFolderPath)") | Should -Be $false
        }
    }

    Context ("[qlogicae_cli setup vs2022 application --is-verbose-logging-enabled] test cases") {        
        It "[qlogicae_cli setup vs2022 application --is-verbose-logging-enabled='']: should not leave an empty folder" {
            $TestResult = qlogicae_cli setup vs2022 application --is-verbose-logging-enabled='' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli setup vs2022 application --is-verbose-logging-enabled='fals']: should not leave an empty folder" {
            $TestResult = qlogicae_cli setup vs2022 application --is-verbose-logging-enabled='fals' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli setup vs2022 application --is-verbose-logging-enabled='tru']: should not leave an empty folder" {
            $TestResult = qlogicae_cli setup vs2022 application --is-verbose-logging-enabled='tru' | Out-String
            
            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli setup vs2022 application --is-verbose-logging-enabled='false']: should not leave an empty folder" {
            $TestResult = qlogicae_cli setup vs2022 application --is-verbose-logging-enabled='false' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            $QLogicaeKmandInstance.IsFolderEmpty("$($QLogicaeKmandInstance.Configurations.DotQLogicaeKmandEnvironmentFolderPath)") | Should -Be $false
        }

        It "[qlogicae_cli setup vs2022 application --is-verbose-logging-enabled='true']: should not leave an empty folder" {
            $TestResult = qlogicae_cli setup vs2022 application --is-verbose-logging-enabled='true' | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
            $QLogicaeKmandInstance.IsFolderEmpty("$($QLogicaeKmandInstance.Configurations.DotQLogicaeKmandEnvironmentFolderPath)") | Should -Be $false
        }
    }
}
