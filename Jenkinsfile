pipeline {
	agent any
	stages{
		stage('Building'){
			steps{
				sh 'echo "Building.."'
				sh 'chmod +x scripts/build-all.sh'
				sh 'scripts/build-all.sh'
				//archiveArtifacts artifacts: '*', fingerprint: true
			}
	}
	stage('Running Tests 1 to 8'){
		steps{
			sh 'echo "Running 1-8..."'
			sh 'chmod +x scripts/run-1-8.sh'
			sh 'scripts/run-1-8.sh'
		}
	}
	stage('Running Test 9'){
		steps{
			sh 'echo "Running 9..."'
			sh 'chmod +x scripts/run-9.sh'
			sh 'scripts/run-9.sh'

		}
	}
	stage('Running Test 10'){
		steps{
			sh 'echo "Running 10..."'
			sh 'chmod +x scripts/run-10.sh'
			sh 'scripts/run-10.sh'
		}
	}
	stage('Running main'){
		steps{
			sh 'echo "Running main..."'
			sh 'chmod +x scripts/run-main.sh'
			sh 'scripts/run-main.sh'
		}
	}
	stage('Build Docker'){
		steps{
			script{
				sh 'docker build -t simonefdr/googletest .'
			}
		}
	}
	stage('Push Docker'){
		steps{
			withCredentials([string(credentialsId: 'dockerpwd', variable: 'dockerhub_pwd')]) {
				sh 'docker login -u simonefdr -p ${dockerhub_pwd}'
			}
			sh 'docker push simonefdr/googletest'
		}
	}
}
}
