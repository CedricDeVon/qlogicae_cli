
Describe "[qlogicae_cli about] test suite" {
    BeforeAll {
        . $PSScriptRoot/imports.ps1

        QLogicaeKmand_BeforeAllTestsSetup
    }

    AfterAll {
        QLogicaeKmand_AfterAllTestsSetup
    }

    Context "[qlogicae_cli about] test cases" {
        It "[qlogicae_cli about]: should not be null or empty" {
            $TestResult = qlogicae_cli about | Out-String
            QLogicaeKmand_ConsoleLog -Text $TestResult

            $TestResult | Should -Not -BeNullOrEmpty
        }
    }
}
