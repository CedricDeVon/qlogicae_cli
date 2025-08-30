
Describe "[qlogicae_cli] test suite" {
    BeforeAll {
        . qlogicae/kmand/scripts/imports.ps1

        $QLogicaeKmandInstance.BeforeAllTestsSetup()
    }

    AfterAll {
        $QLogicaeKmandInstance.AfterAllTestsSetup()
    }

    Context "[qlogicae_cli] test cases" {
        It "[qlogicae_cli]: should be null or empty" {
            $TestResult = qlogicae_cli | Out-String

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli --help]: should not be null or empty" {
            $TestResult = qlogicae_cli --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }
}
