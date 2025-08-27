
Describe "[qlogicae_cli about] test suite" {
    BeforeAll {
        . $PSScriptRoot/qlogicae/configurations/imports.ps1
    }

    AfterAll {

    }

    It "[qlogicae_cli about]: should not be null or empty" {
        $TestResult = qlogicae_cli about | Out-String        
        QLogicaePesterTest_Log -Text $TestResult

        $TestResult | Should -Not -BeNullOrEmpty
    }
}
