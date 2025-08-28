
Describe "[qlogicae_cli about] test suite" {
    BeforeAll {
        . $PSScriptRoot/imports.ps1

        $QLogicaeKmandInstance.BeforeAllTestsSetup()
    }

    AfterAll {
        $QLogicaeKmandInstance.AfterAllTestsSetup()
    }

    Context "[qlogicae_cli about] test cases" {
        It "[qlogicae_cli about]: should not be null or empty" {
            $TestResult = qlogicae_cli about | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }
}
