
Describe "[qlogicae_cli deploy] test suite" {
    BeforeAll {
        . qlogicae/kmand/scripts/imports.ps1

        $QLogicaeKmandInstance.BeforeAllTestsSetup()
    }

    AfterAll {
        $QLogicaeKmandInstance.AfterAllTestsSetup()
    }

    Context ("[qlogicae_cli deploy] test cases") {
        It "[qlogicae_cli deploy]: should terminate" {
            $TestResult = qlogicae_cli deploy | Out-String        

            $TestResult | Should -BeNullOrEmpty
        }

        It "[qlogicae_cli deploy --help]: should not be null or empty" {
            $TestResult = qlogicae_cli deploy --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }

    Context ("[qlogicae_cli deploy inno-setup] test cases") {
        It "[qlogicae_cli deploy inno-setup --help]: should not be null or empty" {
            $TestResult = qlogicae_cli deploy inno-setup --help | Out-String
            $QLogicaeKmandInstance.ConsoleLog($TestResult)

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }
}
