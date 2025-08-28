
Describe "[qlogicae_cli about] test suite" {
    BeforeAll {
        . $PSScriptRoot/imports.ps1

        $QlogicaeKmandInstance.BeforeAllTestsSetup()
    }

    AfterAll {
        $QlogicaeKmandInstance.AfterAllTestsSetup()
    }

    Context "[qlogicae_cli about] test cases" {
        It "[qlogicae_cli about]: should not be null or empty" {
            $TestResult = qlogicae_cli about | Out-String
            $QlogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }
}
