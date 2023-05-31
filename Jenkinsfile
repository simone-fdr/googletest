pipeline {
  agent any
  stages {
    stage('Checkout') {
      steps {
        checkout([$class: 'GitSCM', branches: [[name: '*/main']], doGenerateSubmoduleConfigurations: false, extensions: [], submoduleCfg: [], userRemoteConfigs: [[credentialsId: 'Def', url: 'https://github.com/Scorza9/googletest']]])
      }
    }

    stage('Build') {
      steps {
        sh "mkdir -p ${BUILD_DIR}"
        dir(path: BUILD_DIR) {
          sh 'cmake ..'
          sh 'make'
        }

      }
    }

    stage('Test') {
      steps {
        dir(path: BUILD_DIR) {
          sh './main'
        }

      }
    }

  }
  environment {
    BUILD_DIR = 'build'
  }
  post {
    always {
      sh "rm -rf ${BUILD_DIR}"
    }

  }
}
